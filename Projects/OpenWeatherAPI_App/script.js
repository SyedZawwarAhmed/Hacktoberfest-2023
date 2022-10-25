// import api_key from './apiKey'

let lat, lon, temp_unit, CityName
CityName = 'london'
temp_unit = 'metric'
document.getElementById("london").addEventListener('click', () => {
    CityName = 'london'
    UpadateWeather(CityName)
})
document.getElementById("sydney").addEventListener('click', ()=> {
    CityName = 'sydney'
    UpadateWeather(CityName)
})
document.getElementById("tokyo").addEventListener('click', () => {
    CityName = 'tokyo'
    UpadateWeather(CityName)
})
document.getElementById("toronto").addEventListener('click', ()=> {
    CityName = 'toronto'
    UpadateWeather(CityName)
})
document.getElementById("paris").addEventListener('click', ()=> {
    CityName = 'paris'
    UpadateWeather(CityName)
})

document.getElementById("cent").addEventListener('click', () => {
    temp_unit='metric'
    UpadateWeather(CityName)
})

document.getElementById("fah").addEventListener('click', ()=> {
    temp_unit='imperial'
    UpadateWeather(CityName)
})

document.getElementById('search-btn').addEventListener('click', ()=>{
    CityName = document.getElementById('search').value
    UpadateWeather(CityName)
})

UpadateWeather(CityName)

async function UpadateWeather(cityName){
    await findCurrentWeather(cityName)
    findDailyFourcast(lat, lon)
    findHourlyForcast(lat,lon)
    document.getElementById('search').value = ''
}

// Current Weather
async function findCurrentWeather(cityName){
    const res = await fetch('https://api.openweathermap.org/data/2.5/weather?q='+cityName+'&appid=f186df2b07aa2ac941d346c89f0d10a9&units='+temp_unit+'')
    const data = await res.json()
    UpdateCurrentWeather(data)
}
function UpdateCurrentWeather(data){
    let city = document.getElementById("city")
    let weather = document.getElementById('weather-type')
    let temperature = document.getElementById('temperature')
    let feelLike = document.getElementById('realfell')
    let humidity = document.getElementById('humidity')
    let wind = document.getElementById('wind')
    let max_temp = document.getElementById('max-temp')
    let min_temp = document.getElementById('min-temp')
    let image = document.getElementById('image')
    let time = document.getElementById("time")
    let day = document.getElementById('day-date')
    let rise_time = document.getElementById('rise-time')
    let set_time = document.getElementById('set-time')
    let mainDiv = document.getElementById('main-div')

    city.innerText = data.name +", " + data.sys.country
    weather.innerText = data.weather[0].main
    temperature.innerText = Math.round(data.main.temp)+'°'
    feelLike.innerText = Math.round(data.main.feels_like)+'°'
    humidity.innerText = Math.round(data.main.humidity)+'%'
    wind.innerText = Math.round(data.wind.speed)+" km/h"
    max_temp.innerText = Math.round(data.main.temp_max)+'°'
    min_temp.innerText = Math.round(data.main.temp_min)+'°'
    image.src = `http://openweathermap.org/img/wn/${data.weather[0].icon}@2x.png`
    time.innerText = SetLocalTime(data.timezone)
    day.innerText = getCurrDate(data.timezone)
    rise_time.innerText = getTime(data.sys.sunrise, data.timezone)
    set_time.innerText = getTime(data.sys.sunset, data.timezone)
    if((Math.round(data.main.temp) < 35 && temp_unit === 'metric') || (Math.round(data.main.temp) < 95 && temp_unit === 'imperial')){
        mainDiv.style.background = 'linear-gradient(to bottom right,rgb(14 116 144) , rgb(29 78 216))'
    }
    else{
        mainDiv.style.background = 'linear-gradient(to bottom right,rgb(161 98 7) , rgb(194 65 12))'
    }

    lat = data.coord.lat
    lon = data.coord.lon
}
function SetLocalTime(data){
    const timezoneInMinutes = data / 60;
    const currTime = moment().utcOffset(timezoneInMinutes).format("h:mm A");
    return currTime
}
function getCurrDate(timezone){
    curr_date = new Date()
    localTime = curr_date.getTime()
    localOffset = curr_date.getTimezoneOffset() * 60000
    utc = localTime + localOffset
    var city = utc + (1000 * timezone)
    new_date = new Date(city)
    return moment(new_date).format('dddd, D MMMM YYYY')
}
function getTime(timeinsec, timezone){
    return getNewDate(timeinsec, timezone).toLocaleTimeString({hour12:true}).slice(0,4)+new_date.toLocaleTimeString({hour12:true}).slice(7,)

}
function getNewDate(suntime, timezone){
    curr_date = new Date(suntime*1000)
    localtime = curr_date.getTime()
    localOffset = curr_date.getTimezoneOffset() * 60000
    utc = localtime + localOffset
    let city = utc + (1000 * timezone)
    new_date = new Date(city)
    return new_date
}

// Daily Fourcast
async function findDailyFourcast(latitude, longitude){
    const res = await fetch('https://api.openweathermap.org/data/2.5/forecast/daily?lat='+latitude+'&lon='+longitude+'&cnt=6&appid=f186df2b07aa2ac941d346c89f0d10a9&units='+temp_unit)
    const data = await res.json()
    UpdateDailyFourcast(data)
}
function UpdateDailyFourcast(fourcast){
    let day_array = ['one', 'two', 'three', 'four', 'five']
    for(let i=1; i<6 ; i++){
        // Setting Days
        document.getElementById(`${day_array[i-1]}`).innerText = getDay(fourcast.list[i].dt,fourcast.city.timezone)

        // Setting Icons
        document.getElementById(`img-${day_array[i-1]}`).src = `http://openweathermap.org/img/wn/${fourcast.list[i].weather[0].icon}@2x.png`

        // Setting Min/Max temps.
        document.getElementById(`temp-${day_array[i-1]}`).innerText = `${Math.round(fourcast.list[i].temp.max)}° / ${Math.round(fourcast.list[i].temp.min)}°`
    }
}
function getDay(time,timezone){
    const options = { weekday: 'short'};
    return getNewDate(time, timezone).toLocaleDateString('en-US',options)
}


// Hourly Fourcast
async function findHourlyForcast(latitude, longitude){
    const res = await fetch(`https://pro.openweathermap.org/data/2.5/forecast/hourly?lat=${latitude}&lon=${longitude}&appid=f186df2b07aa2ac941d346c89f0d10a9&cnt=6&units=${temp_unit}`)
    const data = await res.json()
    UpdateHourlyForcast(data)
}
function UpdateHourlyForcast(forcast){
    let day_array = ['one', 'two', 'three', 'four', 'five']
    for(let i=0; i<5 ; i++){
        // Setting Hours
        document.getElementById(`t-${day_array[i]}`).innerText = getTime(forcast.list[i].dt, forcast.city.timezone)

        // Setting Icons
        document.getElementById(`${day_array[i]}-img`).src = `http://openweathermap.org/img/wn/${forcast.list[i].weather[0].icon}@2x.png`

        // Setting Temp
        document.getElementById(`${day_array[i]}-temp`).innerText = `${Math.round(forcast.list[i].main.temp)}°`
    }

}