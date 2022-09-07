var list = document.getElementById("Animelist");

function addtext() {
    var Textinput = document.getElementById("Textinput").value;
    var Entry = document.createElement("li");

    Entry.appendChild(document.createTextNode(Textinput));
    list.appendChild(Entry);

    document.getElementById("Textinput").value = "";
}
