#ifndef RS_DEMO_GDAL_H
#define RS_DEMO_GDAL_H


//Qt include
#include "ui_rs_demo_gdal.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QDialog>
#include <QErrorMessage>
#include <QScrollArea>
#include <QTextEdit>
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QGraphicsView>
#include <QImage>
#include <QMessageBox>
#include <QInputDialog>
#include <QScrollBar>
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>
#include <QKeyEvent>
#include <QProgressDialog>
#include <QBoxLayout>
#include <string>
#include <iostream>
#include "gdal_priv.h"

namespace Ui {
class RS_DEMO_GDAL;
}

class RS_DEMO_GDAL : public QMainWindow
{
    Q_OBJECT

public:
    explicit RS_DEMO_GDAL(QWidget *parent = 0);
    ~RS_DEMO_GDAL();
    GDALDataset* pDataSrc;
    GDALDataset* pDataOri;
    GDALDataset* pData;

    QString qfilename;

private:
    Ui::RS_DEMO_GDAL *ui;

    QErrorMessage *errordlg;

    //file menu
    QMenu *menu_file;
    QAction *act_open;
    QAction *act_save;
    QAction *act_saveas;

    //enhancement menu
    QMenu *menu_enhance;
    QMenu *menu_filter;
    QAction *act_filt_mean;
    QAction *act_filt_median;
    QAction *act_filt_gaussian;
    QAction *act_sharpen;
    QAction *act_histequ;
    QAction *act_help;

    //tool menu
    QMenu *menu_tool;
    QAction *act_resample;
    QAction *act_cut;
    QMenu *menu_edgedetect;
    QAction *act_sobel;
    QAction *act_prewitt;
    QAction *act_laplacian;
    QAction *act_canny;
    QAction *act_roberts;
    QMenu *menu_segmentation;
    QAction *act_otsu;
    QAction *act_fixed;
    QAction *act_adapt;

    QMenu *menu_changedetect;
    QAction *act_changedetect;
    QAction *act_changedetect_help;


    //view menu
    QMenu *menu_view;
    QAction *act_grid;

    //temp
    QAction *act_confirm;

    QAction *act_helpmain;

    //extension
    QAction *DrawHist_origin;
    QAction *Save_origin;
    QAction *DrawHist_after;
    QAction *Save_after;
    QLabel *status;
    QAction *Zoom_origin;
    QAction *Zoom_after;

    QAction *act_zoomin;
    QAction *act_zoomout;

    //ui contents
    QWidget *widget_center;
    QWidget *view_wid_origin;
    QWidget *view_wid_after;
    /*
    ScrollPicView *view_origin;
    ScrollPicView *view_after;
    ImageInfo *info_origin;
    ImageInfo *info_after;
    RSInfo *rsinfo_origin;
    RSInfo *rsinfo_after;
    DisplayController *displaycontroller_origin;
    DisplayController *displaycontroller_after;
    Histogram *hist;
    Axis_Horizontal *axis_h_origin;
    Axis_Horizontal *axis_h_after;
    Axis_Vertical *axis_v_origin;
    Axis_Vertical *axis_v_after;
    display_change *dischange;

    FileTooLarge *filetoolarge;
*/
    //layout
    QVBoxLayout *layout_main;
    QHBoxLayout *layout_up;
    QHBoxLayout *layout_down;

    //functions
    void init_ui();//initialize ui
    void init_signal_slot();

public slots:
    //void updateview_origin();
    //void updateview_after();

private slots:
    void open();
   /*
    void updateinfo();
    void updatecontroller();
    void confirmaction();
    void setgrid();
    void sharpen();
    void helpsharpen();
    void change_detection();
    void change_detection_help();
    void Ostu2();
    void calc_double_Ostu_Threshold_Unit16(unsigned short * Buf, int ImagesizeX, int ImagesizeY, int * posit1, int * posit2, int * topbound);
    void calc_double_Ostu_Threshold_Unit8(unsigned char * Buf, int ImagesizeX, int ImagesizeY, int * posit1, int * posit2);
    void helpmean();
    void helphist();
    void help();
    void drawhist_origin();
    void drawhist_after();
    void save_origin();
    void save_after();
    void save_menu();
    void segmentation_fixed();
    void updatecursor_origin();
    void updatecursor_after();
    void ImageResample();
    void changedetect();

    void sobel();
    void prewitt();
    void canny();
    void otsu();
    void laplacian();
    void roborts();

    void filter_mid();
    void filter_mean();
    void filter_gauss();
    void histequalization();
    void ImageCut();

    void enable_zoom_origin();
    void enable_zoom_after();
    */

};

#endif // RS_DEMO_GDAL_H
