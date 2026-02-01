function requestArtifact() {
    updateOutput("INITIALIZING RETRIEVAL SEQUENCE...");

    setTimeout(() => {
        fetch("/artifact")
            .then(res => res.text())
            .then(data => {
                updateOutput("ERROR: SECURITY CLEARANCE INSUFFICIENT.\n\n" +
                    "[SYSTEM MESSAGE]\n" + data);
            })
            .catch(err => {
                updateOutput("CONNECTION FAILURE.\n" + err);
            });
    }, 800);
}

function getHint() {
    updateOutput("QUERYING SYSTEM INTELLIGENCE...");

    setTimeout(() => {
        fetch("/hint")
            .then(res => res.json())
            .then(data => {
                updateOutput("[INTELLIGENCE RECEIVED]\n\n" +
                    "> " + data.hint);
            })
            .catch(err => {
                updateOutput("INTELLIGENCE QUERY FAILED.");
            });
    }, 600);
}

function updateOutput(text) {
    const output = document.getElementById("output");
    output.innerText = text;
    // Simple typewriter effect simulation (already fully visible but forces attention)
    output.style.opacity = 0.5;
    setTimeout(() => output.style.opacity = 1, 100);
}
