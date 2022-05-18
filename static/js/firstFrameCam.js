// if (document.addEventListener) {
//     document.addEventListener('contextmenu', function(e) {
//       alert("You've tried to open context menu"); //here you draw your own menu
//       e.preventDefault();
//     }, false);
//   } else {
//     document.attachEvent('oncontextmenu', function() {
//       alert("You've tried to open context menu");
//       window.event.returnValue = false;
//     });
//   }

document.addEventListener('keydown', function(event)
{
  var code = event.keyCode || event.which;
  if (code === 9) {  
    // alert("Hello Tab key")
    const Entry_Line = document.getElementById("Entry-Line");
    const Entry_Dir = document.getElementById("Entry-Dir");
    const Exit_Line = document.getElementById("Exit-Line");
    const Exit_Dir = document.getElementById("Exit-Dir");
    if(Entry_Line.checked === true) {
        Entry_Line.checked = false;
        Entry_Dir.checked = true; 
    }
    else if(Entry_Dir.checked === true) {
        Entry_Dir.checked = false;
        Exit_Line.checked = true; 
    }
    else if(Exit_Line.checked === true) {
        Exit_Line.checked = false;
        Exit_Dir.checked = true; 
    }
    else if(Exit_Dir.checked === true) {
        Exit_Dir.checked = false;
        Entry_Line.checked = true; 
    }
  }
});



const videoFile = document.getElementById("videoId").innerHTML;
let applyButton = document.getElementById('applyButton');

applyButton.onclick = function (e) {
    e.preventDefault();
    const Entry_Line_span = document.getElementById("Entry-Line-span").innerHTML;
    const Entry_Dir_span = document.getElementById("Entry-Dir-span").innerHTML;
    const Exit_Line_span = document.getElementById("Exit-Line-span").innerHTML;
    const Exit_Dir_span = document.getElementById("Exit-Dir-span").innerHTML;

    if (Entry_Line_span === ' - - ' || Entry_Dir_span === ' - - ' || Exit_Line_span === ' - - ' || Exit_Dir_span === ' - - ') {
        alert('Please Draw all the Lines and Directions and then click the apply button.')
    }
    else {

        let points = {
            'videoFile': videoFile, 'Entry_Line': Entry_Line_span, 'Entry_Dir': Entry_Dir_span, 'Exit_Line': Exit_Line_span, 'Exit_Dir': Exit_Dir_span
        };
        console.log(points)
        const request = new XMLHttpRequest();
        request.open('POST', `/analyzeCam/${JSON.stringify(points)}`);
        // request.open('POST', `/analyze`);

        request.send();
        location.href = '/queue';
    }

    // Replace localhost and the folder name
    // based on your setup
    // location.href = 'http://localhost/jsredirect/home.html';
}
