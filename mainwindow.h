#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

#include "QVTKImageWidget.h"
#include <vtkEventQtSlotConnect.h>


class QAction;

namespace Ui
{
  class MainWindow;
}
//!Main window for user interaction
/*!
  This class has the main interaction function to load volume images.
*/
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void addLogText(QString str);

  /**
   * \brief return this display widget
   * \param[out] this display widget 
   */
  QVTKImageWidget* getDisplayWidget();




private:

  Ui::MainWindow *ui;

  /** \brief The filename of each selected image */
  QStringList imagesFilenames;

  /** \brief The filenames of each selected volume image */
  QStringList volumeImagesFilenames;

  /** \brief The filename of the rotation data for each image */
  QString volumeRotationData;

   /** \brief The filename of the translation data for each image */
  QString volumeTranslationData;

   /** \brief The filename of the estimated parameters in the calibration */
  QString volumeCalibrationData;

  /** \brief The filename of the selected volume */
  QString volumeFilename;

  QString textOnTextArea;

  /**
   * Central widget for display image purposes
   */
  QVTKImageWidget *displayWidget;


  vtkSmartPointer<vtkEventQtSlotConnect> Connections;

private slots:

  /**
   * \brief Add image folder to application
   */
  void addImages();

  /** 
   * \brief Display selected image with the image slider
   */
  void displaySelectedImage(int idx);

  /**
   * \brief Set selected opacity for the displayed volume
   */
  void setSelectedOpacity(int idx);

  /**
   * \brief Implements a ultrasound 3D probe calibration, for navigate with the 
   * probe
   */
  void probeCalibration();

  /**
   * \brief Implements a needle calibration, for navigate with the
   * needle
   */
  void needleCalibration();

  /**
   * \brief Set the image, rotation, translation and calibration parameters file name
   */
  void openVolumeData();
  
  /**
   * \brief Print message in logger
   */
  void print();

  /**
   * \brief Calls the VolumeReconstructionWidget.h to generate a new volume
   *with the loaded data
   */
  void volumeReconstruction();

  /**
   * \brief Set a volume filename
   */
  void openVolume();

  /**
  * \brief Check the error of the etimated parameters by probeCalibration
  */
  void checkCalibrationError();

  /**
  * \brief Check the error of the etimated parameters by needleCalibration
  */
  void checkNeedleCalibration();
  /**
  * \brief Crop Ultrasound Images
  */
  void cropImages();

  /**
  * \brief Display the virtual Needle biopsy scene
  */
  void display3DScene();


};




#endif // MAINWINDOW_H
