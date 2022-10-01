const api_key = "876eacbfd28512c54ede66d0e0cbf7c0";
const input_data = document.querySelector("#search-data");
const location_btn = document.querySelector("#search-btn");
const location_field = document.querySelector(".weather-location");
const weather_details = document.querySelector(".weather-data");
const weather_description = document.querySelector(".weather-status");
const main = document.querySelector("#main");

//event listeners
location_btn.addEventListener("click", () => {
  if (navigator.geolocation) {
    //if location permission is granted then function call
    getweatherlat();
  }
});
input_data.addEventListener("keypress", function (e) {
  if (e.key === "Enter") {
    //enter to start the process
    getweather(input_data.value);

    input_data.value = " ";
    // console.log("press");
  }
});

function getweather(location) {
  //fetching the api

  fetch(
    // `https://api.openweathermap.org/data/3.0/onecall?q=${location}.04&exclude=hourly,minutely&appid=${api_key}&units=metric`
    `https://api.openweathermap.org/data/2.5/weather?q=${location}&appid=${api_key}&units=metric`
  )
    .then((response) => {
      //channgring it to a object
      return response.json();
    })
    .then((data) => {
      console.log(data);

      background_setter(location);

      //destructing the object to take the the datas
      const { name } = data;
      const { icon, description } = data.weather[0];
      const { temp, humidity, pressure } = data.main;
      const { speed } = data.wind;
      const country = data.sys.country;

      // calling the function that sets the data in the dom
      showdata(
        name,
        icon,
        description,
        temp,
        humidity,
        pressure,
        speed,
        country
      );
    })
    .catch((error) => {
      alert("Location not found");
    });
}
function background_setter(area) {
  //set the background img according to the location

  main.style.background = `url('https://source.unsplash.com/1600x900/?${area}')no-repeat center center/cover`;
}
function showdata(
  name,
  icon,
  description,
  temp,
  humiditys,
  pressure,
  speed,
  country
) {
  location_field.innerHTML = `${name}, ${country}`;
  document.querySelector(
    ".ico"
  ).src = `https://openweathermap.org/img/wn/${icon}.png`;
  weather_description.innerHTML = description;
  weather_details.innerHTML = " ";
  var days = document.createElement("div");
  var day = date_cal();
  days.innerHTML = day;
  weather_details.appendChild(days);
  var tmeprature = document.createElement("div");
  tmeprature.classList.add("temperature");
  tmeprature.innerHTML = temp + "°c";
  weather_details.appendChild(tmeprature);
  var humidity = document.createElement("div");
  humidity.innerHTML = "Humidity: " + humiditys + " %";
  weather_details.appendChild(humidity);
  var presser = document.createElement("div");
  presser.innerHTML = "pressure: " + pressure + " pa";
  weather_details.appendChild(presser);
  var winds = document.createElement("div");
  winds.innerHTML = "wind speed: " + speed + " km/hr";
  weather_details.appendChild(winds);
}
function date_cal() {
  let time = new Date();
  let date = time.getDate();
  let day = time.getDay();
  let days = [
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thrusday",
    "Friday",
    "Saturday",
  ];
  let format = days[day] + "," + date;
  return format;
}
function getweatherlat() {
  navigator.geolocation.getCurrentPosition((success) => {
    let { latitude, longitude } = success.coords;
    fetch(
      `https://api.openweathermap.org/data/2.5/weather?lat=${latitude}&lon=${longitude}&appid=${api_key}&units=metric`
    )
      .then((response) => {
        return response.json();
      })
      .then((data) => {
        const { name } = data;
        const { icon, description } = data.weather[0];
        const { temp, humidity, pressure } = data.main;
        const { speed } = data.wind;
        const country = data.sys.country;
        showdata(
          name,
          icon,
          description,
          temp,
          humidity,
          pressure,
          speed,
          country
        );
      })
      .catch((error) => {
        alert("Location not found");
      });
  });
}
window.addEventListener("DOMContentLoaded", () => {
  if (navigator.geolocation) {
    getweatherlat();
  }
});
