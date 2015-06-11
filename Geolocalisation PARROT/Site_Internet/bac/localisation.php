<!DOCTYPE html>
<html>
	<body>

		<form action="localisation.php" method="get">
			Latitude :<input type="text" name="latitude"><br>
			Longitude :<input type="text" name="longitude"><br>
			<input type="submit">
		</form>
		<?php
		
		if (isset($_GET['latitude']) || isset($_GET['longitude']))
		{
			$latitude = $_GET['latitude'];
			$longitude = $_GET['longitude'];
			
			$lat_ent = floor($latitude);
			$lat_dec = floor(($latitude - $lat_ent)*pow(10,9));
			
			$long_ent = floor($longitude);
			$long_dec = floor(($longitude - $long_ent)*pow(10,9));
			
		}
		else
		{
			$lat_ent = $_GET['lat_ent'];
			$lat_dec = $_GET['lat_dec'];
			$long_ent = $_GET['long_ent'];
			$long_dec = $_GET['long_dec'];
		}
		
		$bdd = new PDO('mysql:host=localhost;dbname=projetbac', 'root', '');
			$req = $bdd->prepare('INSERT INTO localisation(lat_ent ,lat_dec ,long_ent ,long_dec) VALUES (:lat_ent,:lat_dec,:long_ent,:long_dec)');
			$req->execute(array(
				'lat_ent' => $lat_ent,
				'lat_dec' => $lat_dec,
				'long_ent' => $long_ent,
				'long_dec' => $long_dec
			));
		?>

	</body>
</html>