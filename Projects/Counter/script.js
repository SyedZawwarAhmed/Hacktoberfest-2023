document.querySelector('#inc').addEventListener('click', incFunction);
document.querySelector('#res').addEventListener('click', resFunction);
document.querySelector('#dec').addEventListener('click', decFunction);

function incFunction(){
    let count = document.getElementById("count");
    let value = parseInt(count.innerText) + 1
    count.innerText = value
    if(value < 0){
        count.style = "color: red"
    }else if(value === 0){
        count.style = "color: gray"
    }else{
        count.style = "color: green"
    }
    
}
function resFunction(){
    let count = document.getElementById("count")
    count.innerText = 0
    count.style = 'color: grey'

}

function decFunction(){
    let count = document.getElementById("count")
    let value = parseInt(count.innerText) - 1
    count.innerText = value
    if(value < 0){
        count.style = "color: red"
    }else if(value === 0){
        count.style = "color: gray"
    }else{
        count.style = "color: green"
    }
}