var map;
var marker;
var myMarkerImage = new google.maps.MarkerImage('img/viseur.png');

function initialize() {
	var myLatlng = new google.maps.LatLng(48.8953875903117,2.0997297763824463);
	//var myLatlng = new google.maps.LatLng(php_lat,php_long);
	var mapOptions = {
		zoom: 17,
		center: myLatlng,
		mapTypeId: google.maps.MapTypeId.SATELLITE
	}
	map = new google.maps.Map(document.getElementById("map_canvas"), mapOptions);
  
	google.maps.event.addListener(map, 'click', function(event) {   
		document.getElementById('latitude').value=event.latLng.lat();
		document.getElementById('longitude').value=event.latLng.lng();
		placeMarkerClick(event.latLng);
		map.setCenter(event.latLng);
	});
}

function placeMakerGPS() {
	var latitude = document.getElementById('latitude').value;
	var longitude = document.getElementById('longitude').value;
	var coordonne = new google.maps.LatLng(latitude,longitude);
	placeMarkerClick(coordonne);
	map.setCenter(coordonne);
}

function placeMakerPhp() {
	var latitude = php_lat;
	var longitude = php_long;
	document.getElementById('latitude').value = latitude;
	document.getElementById('longitude').value = longitude;
	var coordonne = new google.maps.LatLng(latitude,longitude);
	placeMarkerClick(coordonne);
	map.setCenter(coordonne);
}

function placeMarkerClick(location) {
	if(marker){ //on vérifie si le marqueur existe
		marker.setPosition(location); //on change sa position
	}
	else{
		marker = new google.maps.Marker({ //on créé le marqueur
			position: location,
			icon: myMarkerImage,
			map: map
		});
	}
}

