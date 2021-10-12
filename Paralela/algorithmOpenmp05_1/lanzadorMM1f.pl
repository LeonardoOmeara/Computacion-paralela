#!/usr/bin/perl

# Fichero para automatización de ejecución por lotes de un ejecutable
# dado parámetros de entrada.
# $ --> variable
# @ --> vector
$repeticiones = 10;
@ejecutables = ("matricesApp");
@matrizSize = ("4000");
@cores = ("2","4","6","8");
$path = "/mnt/c/Paralela/pipThreads/";

foreach $exe (@ejecutables) {
	foreach $size (@matrizSize) {
		foreach $core (@cores){
			$fichero = "$path"."Soluciones/"."$exe"."-size"."$size"."-core"."$core";
			#print("$fichero\n");
			for ($i=0; $i<$repeticiones; $i++) {
				#print("$path$exe $size\n");
				system("$path$exe $size $core >> $fichero");
			}
		}
	}
}
exit(1);
