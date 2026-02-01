const express = require("express");
const path = require("path");
const app = express();

const PORT = process.env.PORT || 3000;

app.use(express.static("public"));

app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname, "public", "index.html"));
});


app.get("/hint", (req, res) => {
    const hints = [
        "Some files are not meant to be clicked, but requested.",
        "Developers hide things in plain sight — especially URLs.",
        "If access is denied, ask yourself: what is missing?",
        "Sometimes, digging deep and accessing internal files can yield unexpected results.",
    ];

    const hint = hints[Math.floor(Math.random() * hints.length)];
    res.json({ hint });
});


app.get("/artifact", (req, res) => {
    const access = req.query.access;

    if (access !== "internal") {
        return res.status(403).send("Access denied");
    }

    const filePath = path.join(__dirname, "artifact", "artifact.bin");
    res.download(filePath, "artifact.bin");
});

app.listen(PORT, () => {
    console.log(`CTF challenge running at PORT: ${PORT}`);
});
