#!/usr/bin/perl

# Fichero para automatización de ejecución por lotes de un ejecutable
# dado parámetros de entrada.
# $ --> variable
# @ --> vector
$repeticiones = 30; #30 repeticiones por tamaño de matriz
# @ejecutables = ("MM1c");
@ejecutables = ("MM1c", "MM1f", "MM2f", "MM1fu");
@matrizSize = ("400"); # 4181
$path = "/home/leonardo/Documentos/Paralela/"; #reemplazar {path} por su ruta donde se encuentra ubicado el proyecto (ej: /home/pedro/paralela/Algorithms/threads/) IMPORTANTE: la ruta debe finalizar en /
# @algorithms = ("algorithmOpenmp04/");
@algorithms = ("algorithmOpenmp04/", "algorithmOpenmp05_1/", "algorithmOpenmp05_2/", "algorithmOpenmp06/");
@numThreads = ("1", "2", "4", "6"); #reemplazar {numHilos} por el número de hilos 1, 2, 3, 5, 8, ..., máximo el núcleos que tenga su CPU

$cont = 0;
foreach $exe (@ejecutables) {
    print("\n\t************ ALGORITHM: $exe ************\n\n");
    $algorithmPath = "$path@algorithms[$cont]";
    foreach $thread (@numThreads) {
        print("\n\t\t===== Thread #$thread =====\n");
        foreach $size (@matrizSize) {
            print("\n<<< Matrix size N=$size >>>\n\n");
            $fichero = "$algorithmPath"."Soluciones/"."$exe"."-size"."$size";
            # print("$fichero\n");
            system("echo '----- $thread threads -----' >> $fichero");
            open(FILEHANDLE, "< $fichero") || print("Cannot open file");
            for ($i=0; $i<$repeticiones; $i++) {
                print("- Iteration ".($i+1).": ");
                # print("$algorithmPath$exe $size $thread\n"); #sabemos en qué repetición va nuestro proceso
                system("$algorithmPath$exe $size $thread >> $fichero");
                while (<FILEHANDLE>) {$lastLine = $_}
                print(($lastLine/1000000)." seconds\n");
            }
            close(FILEHANDLE) || print("Cannot close file");
        }
        # sleep(2);
	}
    $cont++;
}
exit(1);
