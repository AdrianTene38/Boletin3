#include "Video.hpp"
void Video::crearRectangular()
{
  VideoCapture video("peaton.mp4");
  // Para abrir la cámara debemos indicar o bien la ruta o bien el número de dispositivo
  // VideoCapture video(0);
  // Comprobamos que el vídeo se haya abierto
  if (video.isOpened())
  {
    Mat decimal;          // Imagen en formato decimal para representar los gradientes
    Mat gx, gy;           // Gradientes en "x" y en "y"
    Mat angulo, magnitud; // Ángulo y magnitud del gradiente
    Mat frame;
    Mat recorte;
    while (3 == 3)
    {
      video >> frame;
      resize(frame, frame, Size(), 0.9, 0.9);

      frame.convertTo(decimal, CV_32F, 1.0 / 255.0); // Creamos una imagen decimal con escala entre 0 y 1 (255 = 1.0)
      // Calculamos los gradientes a través del operador de Sobel
      Sobel(decimal, gx, CV_32F, 1, 0, 1); // Gradiente en "x"
      Sobel(decimal, gy, CV_32F, 0, 1, 1); // Gradiente en "y"
      // Calculamos la magnitud y el ángulo del gradiente
      cartToPolar(gx, gy, magnitud, angulo, true); // Pasamos a coordenas polares
      // Cálculo del HOG
      HOGDescriptor hog(Size(64, 128), Size(16, 16), Size(8, 8), Size(8, 8), 9, 1);
      hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
      vector<Rect> detecciones;
      hog.detectMultiScale(frame, detecciones, 0, Size(8, 8), Size(128, 128), 1.2, 2, false);
      Mat clon = frame.clone();
      cout << "Detecciones: " << detecciones.size() << endl;
      Rect r;
      for (int i = 0; i < detecciones.size(); i++)
      {
        r = detecciones[i];
        r.x += cvRound(r.width * 0.1);
        r.width = cvRound(r.width * 0.8);
        r.y += cvRound(r.height * 0.07);
        r.height = cvRound(r.height * 0.8);

        rectangle(clon, r.tl(), r.br(), Scalar(10, 10, 233), 2);        
        Mat roi = clon(r);
       imwrite("capturarectangulo.jpg",roi); 
      }

      namedWindow("Gx", WINDOW_AUTOSIZE);
      namedWindow("Gy", WINDOW_AUTOSIZE);
      namedWindow("Magnitud", WINDOW_AUTOSIZE);
      namedWindow("Detecciones", WINDOW_AUTOSIZE);

      if (frame.rows <= 0 || frame.cols <= 0)
        break;

      imshow("Video", frame);
      imshow("Gx", gx);
      imshow("Gy", gy);
      imshow("Magnitud", magnitud);
      imshow("Detecciones", clon);

      if (waitKey(250) == 27) //Pedimos que espere 23 milisegundos a que el usario presione la tecla escape
        break;
    }
    destroyAllWindows();
  } 
}

void Video::crearCircular(){

  VideoCapture video("peaton.mp4");
  // Para abrir la cámara debemos indicar o bien la ruta o bien el número de dispositivo
  // VideoCapture video(0);
  // Comprobamos que el vídeo se haya abierto
  if (video.isOpened())
  {
    Mat decimal;          // Imagen en formato decimal para representar los gradientes
    Mat gx, gy;           // Gradientes en "x" y en "y"
    Mat angulo, magnitud; // Ángulo y magnitud del gradiente
    Mat frame;
    Mat recorte;
    while (3 == 3)
    {
      video >> frame;
      resize(frame, frame, Size(), 0.8, 0.8);

      frame.convertTo(decimal, CV_32F, 1.0 / 255.0); // Creamos una imagen decimal con escala entre 0 y 1 (255 = 1.0)
      // Calculamos los gradientes a través del operador de Sobel
      Sobel(decimal, gx, CV_32F, 1, 0, 1); // Gradiente en "x"
      Sobel(decimal, gy, CV_32F, 0, 1, 1); // Gradiente en "y"
      // Calculamos la magnitud y el ángulo del gradiente
      cartToPolar(gx, gy, magnitud, angulo, true); // Pasamos a coordenas polares
      // Cálculo del HOG
      HOGDescriptor hog(Size(48, 96), Size(16, 16), Size(8, 8), Size(8, 8), 9, 1);
      //HOGDescriptor::getDaimlerPeopleDetector();
      //hog.setsvmDetector(HOGDescriptor::getDaimlerPeopleDetector());
      vector<Rect> detecciones;
      hog.setSVMDetector(HOGDescriptor::getDaimlerPeopleDetector());
      hog.detectMultiScale(frame, detecciones, 0, Size(8, 8), Size(128, 128), 0.9, 2, false);

      Mat clon = frame.clone();
      cout << "Detecciones: " << detecciones.size() << endl;
      Rect r;
      for (int i = 0; i < detecciones.size(); i++)
      {
        r = detecciones[i];
        r.x += cvRound(r.width * 0.1);
        r.width = cvRound(r.width * 0.8);
        r.y += cvRound(r.height * 0.07);
        r.height = cvRound(r.height * 0.8);

        rectangle(clon, r.tl(), r.br(), Scalar(10, 10, 233), 2);
        Mat roi = clon(r);
       imwrite("capturacircular.jpg",roi); 
      }

      namedWindow("Gx", WINDOW_AUTOSIZE);
      namedWindow("Gy", WINDOW_AUTOSIZE);
      namedWindow("Magnitud", WINDOW_AUTOSIZE);
      namedWindow("Detecciones", WINDOW_AUTOSIZE);

      if (frame.rows <= 0 || frame.cols <= 0)
        break;

      imshow("Video", frame);
      imshow("Gx", gx);
      imshow("Gy", gy);
      imshow("Magnitud", magnitud);
      imshow("Detecciones", clon);

      if (waitKey(250) == 27) //Pedimos que espere 23 milisegundos a que el usario presione la tecla escape
        break;
    }
    destroyAllWindows();
  }
} 