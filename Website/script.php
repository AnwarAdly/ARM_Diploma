<?php
if( isset ($_GET['status']))
	if ($_GET['status'] == 'ON'){
		header ("Location:on.html");
	}
	else if ($_GET['status'] == 'OFF'){
		header ("Location:off.html");		
	}


?>