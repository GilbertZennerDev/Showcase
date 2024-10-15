const stage = document.getElementById("stage");

const movie = [{
    title: "The Great One",
    summary: "A great movie",
    year: "2025",
    genre: "Adventure",
}, {
    title: "Findet Nemo",
    summary: "Boah",
    year: "1999",
    genre: "Adventure",
}, {
    title: "The Great One",
    summary: "A great movie",
    year: "2025",
    genre: "Adventure",
}, {
    title: "Findet Nemo",
    summary: "Boah",
    year: "1999",
    genre: "Adventure",
}, {
    title: "The Great One",
    summary: "A great movie",
    year: "2025",
    genre: "Adventure",
}, {
    title: "Findet Nemo",
    summary: "Boah",
    year: "1999",
    genre: "Adventure",
}, {
    title: "The Great One",
    summary: "A great movie",
    year: "2025",
    genre: "Adventure",
}, {
    title: "Findet Nemo",
    summary: "Boah",
    year: "1999",
    genre: "Adventure",
}, {
    title: "The Great One",
    summary: "A great movie",
    year: "2025",
    genre: "Adventure",
}, {
    title: "Findet Nemo",
    summary: "Boah",
    year: "1999",
    genre: "Adventure",
},];

const names = ["title", "summary", "year", "genre"];

const elements = ["Movie Title", "Movie Summary", "Genre", "Length", "Year :"];

// Creating the Stage Content
const amountmovies = 100;
let i = 0;
while (i < amountmovies) {
    const col = document.createElement("div");
    col.classList.add("col");
    const row = document.createElement("div");
    row.classList.add("row");
    const title = document.createElement("div");
    title.innerHTML = elements[0] + " : " + movie[i][names[0]];
    row.appendChild(title);
    const img = document.createElement("img");
    img.src = "../../Images/starwars.jpg";
    img.height = 200;
    img.classList.add("smallimage");
    row.appendChild(img);
    const summary = document.createElement("div");
    summary.innerHTML = elements[1] + " : " + movie[i][names[1]];
    row.appendChild(summary);
    const year = document.createElement("div");
    year.innerHTML = elements[2] + " : " + movie[i][names[2]];
    row.appendChild(year);
    const genre = document.createElement("div");
    genre.innerHTML = elements[3] + " : " + movie[i][names[3]];
    row.appendChild(genre);
    col.appendChild(row);
    const horibar = document.createElement("div");
    horibar.classList.add("horibar");
    col.appendChild(horibar);
    stage.appendChild(col);
    i++;
}