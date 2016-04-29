// Create a client instance: Broker, Port, Websocket Path, Client ID
client = new Paho.MQTT.Client("iot.eclipse.org", Number(80), "/ws", "dede");

var start = 0;
var steps = 20;
var goal = 50;
// set callback handlers
client.onConnectionLost = onConnectionLost;
client.onMessageArrived = onMessageArrived;

// connect the client
client.connect({onSuccess:onConnect});


// called when the client connects
function onConnect() {
  // Once a connection has been made, make a subscription and send a message.
  console.log("onConnect");
  client.subscribe("dedefishstep");
}

// called when the client loses its connection
function onConnectionLost(responseObject) {
  if (responseObject.errorCode !== 0) {
    console.log("onConnectionLost:"+responseObject.errorMessage);
  }
}

// called when a message arrives
function onMessageArrived(message) {
  console.log("onMessageArrived:"+message.payloadString);
  alert(message.payloadString);

  
  var table = document.getElementById("table_id");
  var d = new Date();
  var n = d.toDateString(); 
  // Create an empty <tr> element and add it to the 1st position of the table:
  var row = table.insertRow();

  // Insert new cells (<td> elements) at the 1st and 2nd position of the "new" <tr> element:
  var cell1 = row.insertCell(0);
  var cell2 = row.insertCell(1);
  cell1.innerHTML = d;

  alert(message.payloadString);
  
  steps = steps + steps % 7;

  if ( steps > 50 ) {
    steps = 50;
  }

  if(start === 0) {
    cell2.innerHTML = "on";
    start = 1;
  } else {
    cell2.innerHTML = "off " + steps + "/" + goal + " steps taken";
    start = 0;
  }
}

function send_goal() {

  var goal_amount = document.getElementById('goal_id').value;
  alert(goal_amount);
  message = new Paho.MQTT.Message(goal_amount);
  message.destinationName = "defi";
  client.send(message);
}

function append_table(message) {

}
