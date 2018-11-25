---
layout: post
title: RV Screen Door 3D Printer Fix
categories: [3D Printing]
tags: [Fusion 360, CR-10]
---

Had a little accident when _leaving_ the RV repair shop.  Finding a replacement door isn't gonna be
easy so time to bust out the digital calipers. Cut out small section that was bent beyond repair and 
sketched up a rough draft of the cross section of the aluminum extrusion.

Went though at least 3 test fits then printed out a 8" piece of plastic extrusion that was a similar
color.

<a href="/assets/rvsd/IMG_1315.jpg" data-lightbox="image-1" data-title="Bent Screen Door">
  <img width="150" src="/assets/rvsd/IMG_1315.jpg"/>
</a>
<a href="/assets/rvsd/IMG_1318.jpg" data-lightbox="image-1" data-title="Bent Section">
  <img width="150" src="/assets/rvsd/IMG_1318.jpg"/>
</a>
<a href="/assets/rvsd/IMG_1319.jpg" data-lightbox="image-1" data-title="Sketch">
  <img width="150" src="/assets/rvsd/IMG_1319.jpg"/>
</a>
<a href="/assets/rvsd/sketch.png" data-lightbox="image-1" data-title="Sketch">
  <img width="150" src="/assets/rvsd/sketch.png"/>
</a>
<a href="/assets/rvsd/IMG_1320.jpg" data-lightbox="image-1" data-title="Door">
  <img width="150" src="/assets/rvsd/IMG_1320.jpg"/>
</a>


<div id="target" class="madeleine"></div>

<script>
window.onload = function(){
    var madeleine = new Madeleine({
      target: 'target', // target div id
      data: '/assets/rvsd/version1.stl', // data path
      path: '/assets/stlview/'  // path to source directory from current html file
    });
     var madeleine2 = new Madeleine({
      target: 'target2', // target div id
      data: '/assets/rvsd/AluminunDoorExtrusion5.stl', // data path
      path: '/assets/stlview/'  // path to source directory from current html file
    });
}; 

</script>

<div id="target2" class="madeleine"></div>





