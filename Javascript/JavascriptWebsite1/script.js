let tmp;

const test = document.getElementById("test");
const image = document.getElementById("image");
const body = document.getElementsByTagName("body");

fetch('https://api.tvmaze.com/search/shows?q=girls',
    {method : 'GET'}
)
.then(Response => Response.json())
.then(json => {
    json.every(
        img = document.createElement("img");
        image.src = show.image.medium;
    );
    //const title = json[0].show.name;
    
    test.innerHTML = title;
})
.catch(error => console.error(error));