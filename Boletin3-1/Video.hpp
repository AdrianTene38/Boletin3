#include <cstring>
#include <iostream>
#include <cstdlib>
#include <opencv2/core/core.hpp>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cmath> // Esta librería contiene las funciones para realizar operaciones matemáticas (sin, cos, tan, log, exp, etc.)
// Cuando se carga la cabecer opencv.hpp automáticamente se cargan las demás cabeceras
//#include <opencv2/opencv.hpp>

#include <opencv2/core/core.hpp> // Contiene los elementos básicos como el objeto Mat (matriz que representa la imagen)
#include <opencv2/highgui/highgui.hpp> // Contiene los elementos para crear una interfaz gráfica básica
// OpenCV no está pensado para crear interfaces gráficas potentes. Se centra en la visión artificial y PDI. Si se desea crear una interfaz gráfica completa, se debe usar QT

#include <opencv2/imgcodecs/imgcodecs.hpp> // Contiene las funcionalidad para acceder a los códecs que permiten leer diferentes formatos de imagen (JPEG, JPEG-2000, PNG, TIFF, GIF, etc.)

// Librerías para acceder al video y para poder escribir vídeos en disco
#include <opencv2/video/video.hpp> 
#include <opencv2/videoio/videoio.hpp>

#include <opencv2/imgproc/imgproc.hpp> // Librería para realizar operaciones de PDI 

#include <opencv2/objdetect/objdetect.hpp> // Librería contiene funciones para detección de objetos

#include <ctime>

using namespace std;
using namespace cv;


class Video
{
public:
    void crearRectangular();  
    void crearCircular();
};