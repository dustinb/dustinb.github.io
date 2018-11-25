---
layout: post
title: Creality CR-10 Calibration
categories: [3D Printing]
tags: [CR-10]
---

For the x, y, z steps per millimeter print out a [20x20 cube][1].  Use calipers and 
measure, I ended up with the following values `x 20.01mm, y 20.00 mm, z: 19.90 mm`

These are all good but Z could use a little adjustment. The formula for getting the new value is below. Steps per
mm is `400` by default, use `M503` command to view current steps.

    (CURRENT * EXPECTED) / MEASURED = NEW
    (400 * 20 / 19.9) = 402.01
    (93 * 100 / 87.5) = 106.28
    
To set in marlin use `M92`: `M92 Z402`. The same formula can be used for extruder steps per mm.  I extruded `100mm`
and measured `87.5` instead. I put these values in [Simplify3D][2] Script tab along with their other default G-code

```text
G28 ; home all axes
M92 Z402 E106; calibration values
G1 Z5 F3000 ; lift
G1 X5 Y10 F1500 ; move to prime
G1 Z0.2 F3000 ; get ready to prime
G92 E0 ; reset extrusion distance
G1 Y80 E10 F600 ; prime nozzle
G1 Y100 F5000 ; quick wipe
```

<script>
window.onload = function(){
    var madeleine = new Madeleine({
      target: 'target', // target div id
      data: '/assets/xyzCalibration_cube.stl', // data path
      path: '/assets/stlview/'  // path to source directory from current html file
    });
}; 

</script>

<div id="target" class="madeleine"></div>

[1]: https://www.thingiverse.com/thing:1278865
[2]: https://www.simplify3d.com/