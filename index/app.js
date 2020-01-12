var Particle = require('particle-api-js');
var particle = new Particle();
var token;

particle.login({username: 'tkim012@uottawa.ca', password: 'Acornjelly-0611'}).then(
  function(data) {
    token = data.body.access_token;
    console.log('Log in Success');
    console.log('token is: ' + token);
  },
  function (err) {
    console.log('Could not log in.', err);
  }
);

var devicesPr = particle.listDevices({auth:"720cdb8b2eb0ce1ae07457c97062277148613654"});

devicesPr.then(
  function(devices){
    console.log('Devices: ', devices.body[0].name);
    content = "Device name: " + devices.body[0].name;
  },
  function(err){
    console.log('List devices call failed: ',err);
  }
);

function ledOn(){
  var fnPr = particle.callFunction({ deviceId: 'tonylte', name: 'led', argument: 'on', auth: '720cdb8b2eb0ce1ae07457c97062277148613654' });

  fnPr.then(
    function(data) {
      console.log('Function called succesfully:', data);
    }, function(err) {
      console.log('An error occurred:', err);
    });
}

function ledOff(){
  var fnPr = particle.callFunction({ deviceId: 'tonylte', name: 'led', argument: 'off', auth: '720cdb8b2eb0ce1ae07457c97062277148613654' });

  fnPr.then(
    function(data) {
      console.log('Function called succesfully:', data);
    }, function(err) {
      console.log('An error occurred:', err);
    });
}
ledOn();
