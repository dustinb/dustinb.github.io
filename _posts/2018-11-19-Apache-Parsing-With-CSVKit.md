---
layout: post
title: Parsing User Agents From Apache Logs
categories: [DevOps]
tags: [Apache]
excerpt_separator: <!--more-->
---

Needed to parse some user agents out of Apache log files.  After looking around at various ways, [awk][3], `csvkit`, and
  other processor, ended up using `cut` with `"` as delimiter. 
 
    zcat 2018-*_log.gz | grep 'POST /auctions.ltemplate=auction_live.lcommtypeid=168.* 200' | cut -d\" -f 6 | sort | uniq -c -d
    
<!--more-->
    
```text
      3 Mozilla/5.0 (iPad; CPU OS 10_3_1 like Mac OS X) AppleWebKit/603.1.30 (KHTML, like Gecko) Version/10.0 Mobile/14E304 Safari/602.1
      2 Mozilla/5.0 (iPad; CPU OS 10_3_3 like Mac OS X) AppleWebKit/603.1.30 (KHTML, like Gecko) CriOS/64.0.3282.112 Mobile/14G60 Safari/602.1
      2 Mozilla/5.0 (iPad; CPU OS 10_3_3 like Mac OS X) AppleWebKit/603.1.30 (KHTML, like Gecko) CriOS/69.0.3497.71 Mobile/14G60 Safari/602.1
      9 Mozilla/5.0 (iPad; CPU OS 10_3_3 like Mac OS X) AppleWebKit/603.3.8 (KHTML, like Gecko) Version/10.0 Mobile/14G60 Safari/602.1
      5 Mozilla/5.0 (iPad; CPU OS 11_1_1 like Mac OS X) AppleWebKit/604.3.5 (KHTML, like Gecko) Version/11.0 Mobile/15B150 Safari/604.1
     11 Mozilla/5.0 (iPad; CPU OS 11_1_2 like Mac OS X) AppleWebKit/604.3.5 (KHTML, like Gecko) Version/11.0 Mobile/15B202 Safari/604.1
      2 Mozilla/5.0 (iPad; CPU OS 11_2_5 like Mac OS X) AppleWebKit/604.5.6 (KHTML, like Gecko) Version/11.0 Mobile/15D60 Safari/604.1
      2 Mozilla/5.0 (iPad; CPU OS 11_2_6 like Mac OS X) AppleWebKit/604.1.34 (KHTML, like Gecko) GSA/46.0.189829128 Mobile/15D100 Safari/604.1
      7 Mozilla/5.0 (iPad; CPU OS 11_2 like Mac OS X) AppleWebKit/604.4.7 (KHTML, like Gecko) Mobile/15C114
      3 Mozilla/5.0 (iPad; CPU OS 11_2 like Mac OS X) AppleWebKit/604.4.7 (KHTML, like Gecko) Version/11.0 Mobile/15C114 Safari/604.1
     11 Mozilla/5.0 (iPad; CPU OS 11_3 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/11.0 Mobile/15E148 Safari/604.1
      4 Mozilla/5.0 (iPhone; CPU iPhone OS 10_3_3 like Mac OS X) AppleWebKit/603.3.8 (KHTML, like Gecko) Version/10.0 Mobile/14G60 Safari/602.1
      2 Mozilla/5.0 (iPhone; CPU iPhone OS 11_1 like Mac OS X) AppleWebKit/604.3.5 (KHTML, like Gecko) Version/11.0 Mobile/15B93 Safari/604.1
      6 Mozilla/5.0 (iPhone; CPU iPhone OS 11_2_1 like Mac OS X) AppleWebKit/604.4.7 (KHTML, like Gecko) Version/11.0 Mobile/15C153 Safari/604.1
```  
    
Along the way found this [user agent parser][5] ported to many languages. Using the user agent parser you can cut it 
down to major version only and get better idea of usage without the minor versions treated as different browser.

```php
  $parser = Parser::create();
  $result = $parser->parse($ua);
  //$uniq = $result->ua->family .  ' ' . $result->ua->major . ' ' . $result->os->family . ' ' . $result->os->major;            // Safari
  $uniq = $result->ua->family .  ' ' . $result->os->family . ' ' . $result->os->major;            // Safari
```

Final output was 

```text
      2 Amazon Silk Android 4
    101 Chrome Mac OS X 10
     19 Chrome Mobile Android 5
      6 Chrome Mobile Android 6
     14 Chrome Mobile Android 7
      1 Chrome Mobile Android 8
      4 Chrome Mobile iOS iOS 10
      2 Chrome Mobile iOS iOS 12
    218 Chrome Windows 10
    152 Chrome Windows 7
      1 Chrome Windows 8
     97 Chrome Windows 8.1
```
[1]: https://stackoverflow.com/questions/21294997/pip-connection-failure-cannot-fetch-index-base-url-http-pypi-python-org-simpl
[2]: https://pypi.org/project/pip/
[3]: https://stackoverflow.com/questions/29642102/how-to-make-awk-ignore-the-field-delimiter-inside-double-quotes
[4]: https://unix.stackexchange.com/questions/16885/how-would-i-extract-the-user-agent-strings-from-a-log-file
[5]: https://www.uaparser.org/