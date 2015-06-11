<!DOCTYPE html>
<html>

	<head>
		<meta name="viewport" content="initial-scale=1.0, user-scalable=no" />
		<link rel="stylesheet" type="text/css" href="css.css" />
		<script type="text/javascript" src="http://maps.google.com/maps/api/js?sensor=true"></script>
		<script type="text/javascript" src="javascript.js"></script>
		<?php $bdd = new PDO('mysql:host=localhost;dbname=projetbac', 'root', '');
		$test = $bdd ->query('SELECT * FROM  localisation ORDER BY  ID DESC LIMIT 0 , 1');
		$donnee = $test->fetch();
		?>
		<script LANGUAGE="Javascript">
			var php_lat_ent = parseInt('<?php echo $donnee['lat_ent']; ?>');
			var php_lat_dec = parseInt('<?php echo $donnee['lat_dec']; ?>');
			var php_long_ent = parseInt('<?php echo $donnee['long_ent']; ?>');
			var php_long_dec = parseInt('<?php echo $donnee['long_dec']; ?>');
			var php_lat = (php_lat_dec / Math.pow(10,9)) + php_lat_ent;
			var php_long = (php_long_dec / Math.pow(10,9)) + php_long_ent;
		</script>
	</head>

	<body onload="initialize()">

		<div id="map_canvas"></div>
			<div id="coordonne">
				<div onKeyPress="if (event.keyCode == 13) placeMakerGPS()">
					Latitude : <br> <input id="latitude" type="text" name="latitude"><br>
					Longitude : <br> <input id="longitude" type="text" name=""><br>		
					<input type="button" onClick="javascript:placeMakerGPS()" value="Localiser la position"><br>
				</div>
				
				<div>
					<input type="button" onClick="javascript:placeMakerPhp()" value="Localiser le Drone"><br>
				</div>
			</div>
		</div>
  
	</body>
</html>

