document.getElementById("parent-list").addEventListener("click", function (e) {
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