const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
 <head>
   <meta charset="utf-8">   
   <title>VR eyes</title>
   <link rel="stylesheet" href="style.css">

<script>
  // Update DHT22 data dynamically
  function updateSensorData(temperature, humidity) {
    document.getElementById("temperature").innerText = temperature;
    document.getElementById("humidity").innerText = humidity;
  }

  // Fetch data from the server
  function fetchData() {
    fetch("/dhtdata")
      .then(response => response.json())
      .then(data => {
        updateSensorData(data.temperature, data.humidity);
      })
      .catch(error => console.error("Error fetching data:", error));
  }

  // Fetch data initially and then every 10ms seconds (adjust as needed)
  fetchData();
  setInterval(fetchData, 10);
</script>


<div id="dht-data" style="position: absolute; top: 10px; left: 10px;">{DHT_DATA}</div>

</head>
 <body bgcolor="#0A122A" text="#DF7401">

<center>

<img src="http://192.168.4.1/mjpeg/1" alt="leftEYE" width=430>
<img src="http://192.168.4.1/mjpeg/1" alt="rightEYE" width= 430>

</center>
</body>
</html>

)=====";
