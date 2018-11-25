---
layout: post
title: Arduino Button Circuits
categories: [Arduino]
tags: [YouTube, ESP32]
---

Reviewing 2 different button circuits. One being the [classic circuit][1] with resistor to ground the pin which goes HIGH
when the button is pressed.  The other [using INPUT_PULLUP][2] which grounds the pin to LOW without the use of a resistor.

<table>
  <tr>
    <td>Classic Buton</td>
    <td width="20%">&nbsp;&nbsp;</td>
    <td>Input Pullup</td>
  </tr>
  <tr>
    <td><img src="/sketches/Button/Button.png" alt="Classic Button" width="280" /></td>
    <td width="20%">&nbsp;&nbsp;</td>
    <td><img src="/sketches/Button/Button2.png" alt="Simple Pullup" width="280" /></td>
  </tr>
</table>
    

[1]: /sketches/Button/Button1/Button1.ino
[2]: /sketches/Button/Button2/Button2.ino