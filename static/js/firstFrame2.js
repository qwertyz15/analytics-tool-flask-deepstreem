var canvas = document.getElementById("myCanvas");
var context = canvas.getContext('2d');
var img = document.getElementById("scream");
canvas.width = img.width / 2;
canvas.height = img.height / 2;
context.drawImage(img, 0, 0, img.width / 2, img.height / 2);

window.onload = function () {
    // var canvas = document.getElementById("myCanvas");
    var context = canvas.getContext('2d');
    var img = document.getElementById("scream");
    canvas.width = img.width / 2;
    canvas.height = img.height / 2;
    context.drawImage(img, 0, 0, img.width / 2, img.height / 2);
}

var dFlag = false, hitFlag = false; //(dFlag) to check if mouse is currently dragging; (hitFlag) to check if mouse hits a shape
var dragStartLoc;
var snapshot;
var fillStyle = document.getElementById("fillColor");
let pathsry = [];
let startPoints = [];
let endPoints = [];
let types;
let pops = 0;



function welcome() {
    // var canvas = document.getElementById("myCanvas");
    // var context = canvas.getContext('2d');
    // var img = document.getElementById("scream");
    // canvas.width = img.width
    // canvas.height = img.height
    // context.drawImage(img, 0, 0);
}

function checkButton() {    
    if(document.getElementById('Entry-Line').checked) {   
        return "Entry-Line" 
    }   
    else if(document.getElementById('Entry-Dir').checked) {   
        return "Entry-Dir"  
    }   
    else if(document.getElementById('Exit-Line').checked) {   
        return "Exit-Line"
    }   
    else if(document.getElementById('Exit-Dir').checked) {   
        return "Exit-Dir"
    }  
 
}



function drawStyles() {

    context.strokeStyle = '#1dff00';
    context.fillStyle = fillStyle.value;
    context.lineWidth = 3;
    context.lineCap = 'round';
    // console.log(fillStyle.value);
    document.getElementById("body").style.borderColor = fillStyle.value;
    // context.strokeStyle = fillStyle.value;
}

//Writes Coordinates to screen for each event
function drawGps() {
    var posX = dragStartLoc.x;
    var posY = dragStartLoc.y;
    document.getElementById('x-value').innerHTML = Math.floor(posX);
    document.getElementById('y-value').innerHTML = Math.floor(posY);
    document.getElementById("x1-value").innerHTML = "-";
    document.getElementById("y1-value").innerHTML = "-";

}

//Retrieve Coordinates of click
function getGPS(event) {
    var x = event.clientX - canvas.getBoundingClientRect().left,
        y = event.clientY - canvas.getBoundingClientRect().top;

    return { x: x, y: y };
}

//preserve and retrieve Frames to enable drawing multiple shapes
function saveFrame() {
    canvasFrame = context.getImageData(0, 0, canvas.width, canvas.height);
}

function getFrame() {
    context.putImageData(canvasFrame, 0, 0);
}


function submit() {
    drawStyles();

}

function drawBg(color) {

}

// function checkHit(position) {
//     var radius = Math.sqrt(Math.pow((dragStartLoc.x - position.x), 2) + Math.pow((dragStartLoc.y - position.y), 2));

//         if ((positon.x - dragStartLoc.x) * (positon.x - dragStartLoc.x) +
//             (positon.y - dragStartLoc.y) * (positon.y - dragStartLoc.y) <= radius * radius)
//             alert("inside");
//         else
//         alert("outside");
//     }

// }


// function testHit() {
//    takeSnapshot();
//    restoreSnapshot();
//    testHit == true;
//    checkHit();

// }






function drawCircle(position) {
    // console.log(position)
    var radius = Math.sqrt(Math.pow((dragStartLoc.x - position.x), 2) + Math.pow((dragStartLoc.y - position.y), 2));
    context.beginPath();
    context.arc(dragStartLoc.x, dragStartLoc.y, radius, 0, 2 * Math.PI, false);
    context.fill();
    document.getElementById('size').innerHTML = Math.floor(radius);
}

function domCoordinates(position) {
    let sx = (dragStartLoc.x * 2).toString();
    let sy = (dragStartLoc.y * 2).toString();
    let ex = (position.x * 2).toString();
    let ey = (position.y * 2).toString();
    let v = sx+';'+sy+';'+ex+';'+ey+';';
    document.getElementById("x-value").innerHTML = Math.floor(position.x) * 2;
    document.getElementById("y-value").innerHTML = Math.floor(position.y) * 2;
    // console.log(v);
    if(checkButton() === 'Entry-Line') {
        // console.log("Entry-Line");
        document.getElementById("Entry-Line-span").innerHTML = v;
    }
    else if(checkButton() === 'Exit-Line') {
        document.getElementById("Exit-Line-span").innerHTML = v;
    }
    else if(checkButton() === 'Entry-Dir') {
        // console.log("Entry-Line");
        document.getElementById("Entry-Dir-span").innerHTML = v;
    }
    else if(checkButton() === 'Exit-Dir') {
        document.getElementById("Exit-Dir-span").innerHTML = v;
    }
}

function drawLine(position) {
    // console.log(position)
    context.strokeStyle = '#1dff00';
    context.beginPath();
    context.moveTo(dragStartLoc.x, dragStartLoc.y);
    context.lineTo(position.x, position.y);
    context.stroke();
    domCoordinates(position);
}


function drawArrow(position) {
    context.strokeStyle = '#1d00ff';
    context.beginPath();
    var headlen = 10; // length of head in pixels
    var dx = position.x - dragStartLoc.x;
    var dy = position.y - dragStartLoc.y;
    var angle = Math.atan2(dy, dx);
    context.moveTo(dragStartLoc.x, dragStartLoc.y);
    context.lineTo(position.x, position.y);
    context.lineTo(position.x - headlen * Math.cos(angle - Math.PI / 6), position.y - headlen * Math.sin(angle - Math.PI / 6));
    context.moveTo(position.x, position.y);
    context.lineTo(position.x - headlen * Math.cos(angle + Math.PI / 6), position.y - headlen * Math.sin(angle + Math.PI / 6));
    context.stroke();
    domCoordinates(position);
  }


function startDraw(event) {
    dFlag = true;
    dragStartLoc = getGPS(event);
    startPoints.push(dragStartLoc);
    // console.log(dragStartLoc);
    saveFrame();
    drawGps();
}

function drag(event) {
    var position;
    if (dFlag === true) {
        getFrame();
        drawGps();
        position = getGPS(event);
        // drawCircle(position);
        if(checkButton() === "Entry-Line" || checkButton() === "Exit-Line") drawLine(position);
        if(checkButton() === "Entry-Dir" || checkButton() === "Exit-Dir") drawArrow(position);


    }
}

function endDraw(event) {
    dFlag = false;
    saveFrame();
    getFrame();
    var position = getGPS(event);
    // drawCircle(position);
    if(checkButton() === "Entry-Line" || checkButton() === "Exit-Line") drawLine(position);
    if(checkButton() === "Entry-Dir" || checkButton() === "Exit-Dir") drawArrow(position);
    drawBg();
    endPoints.push(position);
    // console.log(position);
    document.getElementById('x1-value').innerHTML = Math.floor(position.x) * 2;
    document.getElementById('y1-value').innerHTML = Math.floor(position.y) * 2;


}

// undo.addEventListener("click",Undo);
const undoElement = document.getElementById("undo");
undoElement.addEventListener("click", Undo);

const redoElement = document.getElementById("redo");
redoElement.addEventListener("click", Redo);

const clearElement = document.getElementById("clear");
clearElement.addEventListener("click", clear);

function clear(){
    // delete everything
    context.clearRect(0,0,canvas.width,canvas.height);
    // context.drawImage(img, 0, 0);
    context.drawImage(img, 0, 0, img.width / 2, img.height / 2);

    document.getElementById("x-value").innerHTML = "-";
    document.getElementById("y-value").innerHTML = "-";
    document.getElementById("Entry-Line-span").innerHTML = '- -';
    document.getElementById("Entry-Dir-span").innerHTML = '- -';
    document.getElementById("Exit-Line-span").innerHTML = '- -';
    document.getElementById("Exit-Dir-span").innerHTML = '- -';
    
    startPoints = [];
    endPoints = [];
}


function clearAll(){
    // delete everything
    context.clearRect(0,0,canvas.width,canvas.height);
    context.drawImage(img, 0, 0, img.width / 2, img.height / 2);
    // context.drawImage(img, 0, 0);
    // startPoints = [];
    // endPoints = [];
}

function drawPaths(){
  // delete everything
  clearAll();
  
  for (let i = 0; i < startPoints.length - pops; i++) {
    dragStartLoc = startPoints[i];
    position = endPoints[i];
    drawLine(position);
  }

}  

function Undo(){
  // remove the last path from the paths array
  pathsry.splice(-1,1);
  if(pops < startPoints.length) pops += 1;
  // draw all the paths in the paths array
  drawPaths();
}

function Redo(){
    // remove the last path from the paths array
    pathsry.splice(-1,1);
    if(pops > 0) pops -= 1;
    // draw all the paths in the paths array
    drawPaths();
  }






document.addEventListener('keyup', event => {
    if (event.code === 'Space') {
        context.clearRect(0, 0, canvas.width, canvas.height);
        context.drawImage(img, 0, 0);
        startPoints = [];
        endPoints = [];
        document.getElementById("size").innerHTML = "-";
        document.getElementById("x-value").innerHTML = "-";
        document.getElementById("y-value").innerHTML = "-";
    }



})

document.onkeyup = function(e) {
  if (e.ctrlKey && e.which == 89) {
    Redo();
  } 
  else if (e.ctrlKey && e.which == 88) {
    Undo();
    // alert("Ctrl + X shortcut combination was pressed");
  } 
  else if (e.ctrlKey && e.which == 67) {
    clear();
    // alert("Ctrl + X shortcut combination was pressed");
  } 
};

// document.addEventListener('keyup', e => {
//     var ctrlDown = false,
//     ctrlKey = 17,
//     cmdKey = 91,
//     vKey = 86,
//     cKey = 67;
//     if (ctrlDown && (e.keyCode == cKey)) {
//         Undo();
//     }
// })





canvas.addEventListener('mousedown', startDraw, false);
canvas.addEventListener('mousemove', drag, false);
canvas.addEventListener('mouseup', endDraw, false);
// fillStyle.addEventListener('input', drawStyles(), false);

window.addEventListener('load', welcome(), true);


