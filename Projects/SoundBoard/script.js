const sounds = [

    'alarm',
    'arcade',
    'coin',
    'fast'
];

sounds.forEach((sound)=>{
    const btn = document.createElement("button");
    btn.classList.add('btn');

    btn.innerText = sound;

    btn.addEventListener('click' ,()=>{
        stopsong();
        document.getElementById(sound).play();
    });
    
    document.body.appendChild(btn);

});

function stopsong(){
    sounds.forEach(sound=>{
        const song = document.getElementById(sound);
        song.pause();
        song.currentTime = 0;
        
    })
}
