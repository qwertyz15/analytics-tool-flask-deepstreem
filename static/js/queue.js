document.getElementById("camLoc").addEventListener("click", function (e) {
    // e.target is our targetted element.
    // try doing console.log(e.target.nodeName), it will result LI
    if (e.target) {

        console.log(e.target.id + " was clicked");
        let videoClicked = e.target.id;
        const request = new XMLHttpRequest();
        request.open('POST', `/firstFrameCam/${JSON.stringify(videoClicked)}`);
        request.send();

    }
});

// var userSelection = document.getElementsByClassName('downloadbtn');
// var letters = {{ filelist|safe }};

// for(var i = 0; i < userSelection.length; i++) {
//   (function(index) {
    
//     userSelection[index].addEventListener("click", function() {
//        console.log("Clicked index: " + index);
//         console.log(letters[index]);

//      })
//   })(i);
// }


function download(fileUrl, fileName) {
    var a = document.createElement("a");
    a.href = fileUrl;
    a.setAttribute("download", fileName);
    a.click();
}

// document.getElementById("downloadbtn")
//     .addEventListener("click", function () {
//         // var text = document.getElementById("text").value;
//         // var filename = "output.txt";
//         x = document.getElementById("licontents").innerHTML
//         console.log(x)
//         // alert('Download Button clicked.')
//         // download('Location1.png', 'Loc1.png');
//     }, false);