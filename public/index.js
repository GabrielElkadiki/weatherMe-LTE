//Google Maps Places Autocomplete API from their website
function initMap() {
  var map = new google.maps.Map(document.getElementById('map'), {
  });
  var card = document.getElementById('pac-card');
  var input = document.getElementById('pac-input');

  var autocomplete = new google.maps.places.Autocomplete(input);

  var infowindow = new google.maps.InfoWindow();
  var infowindowContent = document.getElementById('infowindow-content');
  infowindow.setContent(infowindowContent);

  autocomplete.addListener('place_changed', function() {
    infowindow.close();
    var place = autocomplete.getPlace();
    if (!place.geometry) {
      // User entered the name of a Place that was not suggested and
      // pressed the Enter key, or the Place Details request failed.
      window.alert("No details available for '" + place.name + "'. Please choose a valid city.");
      return;
    }
  });
};

//main function to show itinerary
function itinerary() {
  document.getElementById("area1").style.display = "none";
  document.getElementById("button1").val();

  var name = $(".nameInput").val();
  var numDay = $("select[name=Month]").val();
  var length = document.getElementById("dayInput").val();
  //Get rest of info from form

  document.getElementById("main_form").submit(); //form submission
  //Add code to fill in a table to show the itinerary 
}


//For using jQuery to make divs disappear instead of all one page scrolling
//Transition from name to name2
//Find a better way to get name and name2 (right now not scalable)
function bClick(name,name2) {
  document.getElementById(name).style.display = "none";
  document.getElementById(name2).style.display = "block";
};

