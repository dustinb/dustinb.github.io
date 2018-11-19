---
layout: post
title: ESP8266 Blink & Fade
categories: [Arduino]
tags: [YouTube, ESP8266]
excerpt_separator: <!--more-->
---

Looking closer at the [blink][4] sketch using LED circuit on breadboard.  This site has good explanation
of [breadboard layout][5]. Quick overview of the differences between `digitalWrite` 
and `analogWrite`. To use `analogWrite` for the example fade sketch an external [library][2] is needed

[This][1] is a good reference for the ESP32 pin out.  A main point to note is
 that some of the pins, *34 to 39*, are input only so cannot be set to `pinMode(34, OUTPUT)` for example
won't work.

<iframe width="560" height="315" src="https://www.youtube.com/watch?v=VaFTmUmr8GY" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

[1]: https://randomnerdtutorials.com/esp32-pinout-reference-gpios/
[2]: https://github.com/ERROPiX/ESP32_AnalogWrite
[3]: https://www.arduino.cc/en/Tutorial/KnightRider
[4]: https://www.arduino.cc/en/tutorial/blink
[5]: https://computers.tutsplus.com/tutorials/how-to-use-a-breadboard-and-build-a-led-circuit--mac-54746