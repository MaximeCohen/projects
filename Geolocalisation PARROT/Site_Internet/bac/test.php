<!DOCTYPE html>
<html>
	<body>

		<?php $bdd = new PDO('mysql:host=localhost;dbname=projetbac', 'root', '');
		$test = $bdd ->query('SELECT * FROM  localisation ORDER BY  ID DESC LIMIT 0 , 1');
		$donnee = $test->fetch();
		echo $donnee['latitude'];
		
		?>

	</body>
</html>