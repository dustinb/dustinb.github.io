---
layout: post
title: Lightbox In Jekyll
categories: [Jekyll]
excerpt_separator: <!--more-->
---

To get [lightbox2](https://lokeshdhakar.com/projects/lightbox2/) working I'm using a CDN to include
the proper CSS and JS files.  There are some other methods available via plugins, using HTML in the 
markdown for images serves it's purpose.

<!--more-->

Example:

```html
<a href="/images/xs750.jpg" data-lightbox="image-1" data-title="1978 Yamaha XS750">
  <img width="100" src="/images/xs750.jpg"/>
</a>
<a href="/images/roundporch.jpg" data-lightbox="image-1" data-title="The Round Porch">
  <img width="100" src="/images/roundporch.jpg"/>
</a>
```

Produces:

<a href="/images/xs750.jpg" data-lightbox="image-1" data-title="1978 Yamaha XS750">
  <img width="100" src="/images/xs750.jpg"/>
</a>
<a href="/images/roundporch.jpg" data-lightbox="image-1" data-title="The Round Porch">
  <img width="100" src="/images/roundporch.jpg"/>
</a>

To make these work added the following files from CDN to `_layouts/default.html`

```html
  <link rel="stylesheet" type="text/css" href="https://cdnjs.cloudflare.com/ajax/libs/lightbox2/2.10.0/css/lightbox.min.css" />
  <script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/lightbox2/2.10.0/js/lightbox-plus-jquery.min.js"></script>
```

If I found a plugin that's easy to install and adds the ability to do something like 
`![My Image](/images/dasher.png ":lightbox")` that might be nicer and a bit easier to manage.

