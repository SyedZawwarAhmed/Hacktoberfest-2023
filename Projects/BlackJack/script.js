
let blackjackImages = ['2', '3', '4', '5', '6', '7', '8', '9','10', 'J', 'Q', 'K', 'A']

let blackjackGame = {'2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8':8, '9':9, '10': 10, 'J':10, 'Q':10, 'K':10, 'A':[1, 11]}

let scores = {'you': 0, 'dealer': 0}

let results = {'Wins' : 0, 'Losses' : 0, 'Draws' : 0}

let yourTurn = true, dealing = false;

document.querySelector('#hit-button').addEventListener('click', hitFunction);
document.querySelector('#deal-button').addEventListener('click', dealFunction);
document.querySelector('#submit-button').addEventListener('click', submitFunction);

function hitFunction(){
    let imagevalue = Math.floor(Math.random() * 13)
    var img = document. createElement("img");
    img. src = "images/" + blackjackImages[imagevalue] + ".png";

    if(scores['you'] + blackjackGame[blackjackImages[imagevalue]] > 21){
        let score = document.querySelector('#your-score')
        score.innerHTML = "You Bust!"
        score.style.color = "red"
    }else{
        if(blackjackImages[imagevalue] === 'A'){
            if(scores['you'] < 21 && scores['you'] + blackjackGame[blackjackImages[imagevalue]][1] > 21){
                scores['you'] += blackjackGame[blackjackImages[imagevalue]][0]
                document.querySelector(".your-div").appendChild(img)
            }else if(scores['you'] < 21 && scores['you'] + blackjackGame[blackjackImages[imagevalue]][1] <= 21){
                scores['you'] += blackjackGame[blackjackImages[imagevalue]][1]
                document.querySelector(".your-div").appendChild(img)
            }
        }else if(scores['you'] < 21 && blackjackGame[blackjackImages[imagevalue]]+scores['you'] <= 21){
            scores['you'] += blackjackGame[blackjackImages[imagevalue]]
            document.querySelector(".your-div").appendChild(img)
        }
        let score = document.querySelector('#your-score')
        score.innerHTML = ""+scores['you']
    }
}

function dealFunction(){
    
    scores['you'] = 0
    let yourscore = document.querySelector('#your-score')
    yourscore.innerHTML = 0
    yourscore.style.color = "white"
    
    scores['dealer'] = 0
    let dealerscore = document.querySelector('#dealer-score')
    dealerscore.innerHTML = 0
    dealerscore.style.color = "white"

    let yourimage = document.querySelector(".your-div").querySelectorAll('img')
    let dealerimage = document.querySelector('.dealer-div').querySelectorAll('img')
    for(let i = 0; i < yourimage.length; i++){
        yourimage[i].remove()
    }
    for(let i = 0; i < dealerimage.length; i++){
        dealerimage[i].remove()
    }
    let result = document.querySelector('#result')
        result.innerHTML = "Let's Play"
        result.style.color = "black"
}

function submitFunction(){
    yourScore = scores['you']
    for(let dealerscore = scores['dealer'];true;){
        let imagevalue = Math.floor(Math.random() * 13)
        var img = document. createElement("img");
        
        img. src = "images/" + blackjackImages[imagevalue] + ".png";
        if(blackjackImages[imagevalue] === "A"){
            if(dealerscore + blackjackGame[blackjackImages[imagevalue]][1] > 21){
                b = blackjackGame[blackjackImages[imagevalue]][0]
                actualDealerScore = dealerscore + b
            }else{
                b = blackjackGame[blackjackImages[imagevalue]][1]
                actualDealerScore = dealerscore + b 
            }    
        }else{
            b = blackjackGame[blackjackImages[imagevalue]]
            actualDealerScore = dealerscore + b
        }
        console.log(b)
        if(actualDealerScore > 21){
            let score = document.querySelector('#dealer-score')
            score.innerHTML = "You Bust!"
            score.style.color = "red"
            dealerscore+=b
            b = dealerscore
            break
        }else if(actualDealerScore > yourScore && actualDealerScore < 21){
            document.querySelector(".dealer-div").appendChild(img)
            dealerscore+=b
            let score = document.querySelector('#dealer-score')
            score.innerHTML = ""+dealerscore
            b = dealerscore
            break
        }else if(actualDealerScore < yourScore && actualDealerScore <= 16){
            document.querySelector(".dealer-div").appendChild(img)
            dealerscore+=b
            continue
        }else if(actualDealerScore === yourScore && actualDealerScore < 16){
            document.querySelector(".dealer-div").appendChild(img)
            dealerscore+=b
            continue
        }else if(actualDealerScore === yourScore && actualDealerScore >= 16){
            document.querySelector(".dealer-div").appendChild(img)
            let score = document.querySelector('#dealer-score')
            score.innerHTML = ""+actualDealerScore
            dealerscore+=b
            b = dealerscore
            break
        }else if(actualDealerScore < yourScore && actualDealerScore > 16){
            document.querySelector(".dealer-div").appendChild(img)
            let score = document.querySelector('#dealer-score')
            score.innerHTML = ""+actualDealerScore
            dealerscore+=b
            b = dealerscore
            break
        }
    }
    computewinner(yourScore,b)
    computeresult()
}

function computewinner(yourscore, dealerscore){

    let your_score = document.querySelector('#your-score')
    let dealer_score = document.querySelector('#dealer-score')
    console.log(yourscore)
    console.log(dealerscore)

    if((yourscore > dealerscore && (your_score.innerHTML !== "You Bust!" && dealer_score.innerHTML !== 'You Bust!')) || (dealer_score.innerHTML === 'You Bust!' && your_score.innerHTML !== "You Bust!")){
        let result = document.querySelector('#result')
        result.innerHTML = "You Won"
        result.style.color = "green"
        results['Wins'] += 1
    }else if((yourscore === dealerscore && (your_score.innerHTML !== "You Bust!" && dealer_score.innerHTML !== "You Bust!")) ||(your_score.innerHTML === 'You Bust!' && dealer_score.innerHTML === 'You Bust!')){
        let result = document.querySelector('#result')
        result.innerHTML = "It's a Draw"
        result.style.color = "black"
        results['Draws'] += 1
    }else if(yourscore < dealerscore || your_score.innerHTML === 'You Bust!'){
        let result = document.querySelector('#result')
        result.innerHTML = "You Lost"
        result.style.color = "red"
        results['Losses'] += 1
    }
}

function computeresult(){
    wins = document.querySelector('#win-count')
    wins.innerHTML = results['Wins']

    loss = document.querySelector('#loss-count')
    loss.innerHTML = results['Losses']

    draw = document.querySelector('#draw-count')
    draw.innerHTML = results['Draws']
}

