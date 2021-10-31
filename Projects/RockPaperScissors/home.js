function rps(yourchoice){
    let choices = ["rock", "paper", "scissors"];
    let botchoice = choices[Math.floor(Math.random() * 3)];
    humanchoice = yourchoice.id;
    console.log(humanchoice)
    console.log(botchoice)
    results = getresults(humanchoice, botchoice); // it should return [1, 0]
    console.log(results)
    message = messages(results) // return You Won
    console.log(message)
    finalmessage(humanchoice, message, botchoice)   
}

function getresults(humanchoice, botchoice){
    let database = {"rock":{"rock": 0.5, "paper": 0, "scissors": 1},
                    "paper":{"paper": 0.5, "scissors": 0, "rock": 1},
                    "scissors":{"scissors": 0.5, "rock": 0, "paper": 1}}
    let yourchoice = database[humanchoice][botchoice]
    let AIchoice = database[botchoice][humanchoice]

    return [yourchoice, AIchoice]
}

function messages(result){
    if(result[0] === 1){
        return ("You Won")
    }else if(result[0] === 0.5){
        return ("Tied")
    }else{
        return ("You Lost")
    }
}

function finalmessage(humanchoice, finalmessage, botchoice){
    var Imagedatabase = {"rock": document.getElementById("rock").src, "paper": document.getElementById("paper").src,"scissors": document.getElementById("scissors").src}
    
    document.getElementById("rock").remove()
    document.getElementById("paper").remove()
    document.getElementById("scissors").remove()

    var humanImagediv = document.createElement("div");
    var messagediv = document.createElement("div");
    var botImagediv = document.createElement("div");

    humanImagediv.innerHTML = "<img src ='" + Imagedatabase[humanchoice] + "' height = 150px width = 150px>";
    document.getElementById("flex-box-rps-div").appendChild(humanImagediv);

    messagediv.innerHTML = "<h2>" + finalmessage + "</h2>";
    document.getElementById("flex-box-rps-div").appendChild(messagediv);

    botImagediv.innerHTML = "<img src ='" + Imagedatabase[botchoice] + "'height = 150px width = 150px>";
    document.getElementById("flex-box-rps-div").appendChild(botImagediv);
}