/** @format */

document.addEventListener("mousemove", (e) => {
  const mouseX = e.clientX;
  const mouseY = e.clientY;
  //   console.log(mouseX);
  //   console.log(mouseY);

  const anchor = document.getElementById("anchor"); // getting main image
  const rekt = anchor.getBoundingClientRect(); // using area under the anchor image

  const anchorX = rekt.left + rekt.width / 2;
  const anchorY = rekt.top + rekt.height / 2;

  const angleDeg = angle(mouseX, mouseY, anchorX, anchorY);
  console.log("angle Deg ", angleDeg);

  const Eyes = document.querySelectorAll(".eye");

  Eyes.forEach((eye) => {
    eye.style.transform = `rotate(${90 + angleDeg}deg)`;
  });
});

function angle(cx, cy, ex, ey) {
  const dy = ey - cy;
  const dx = ex - cx;

  const rad = Math.atan2(dy, dx); // Range [-pi , pi]
  const deg = (rad * 180) / Math.PI; // rad to degree
  return deg;
}
