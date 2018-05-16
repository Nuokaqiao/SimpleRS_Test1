#include "rs_demo_gdal.h"


RS_DEMO_GDAL::RS_DEMO_GDAL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RS_DEMO_GDAL)
{
    ui->setupUi(this);

    init_ui();//initialize ui
    //std::cout << "init ui ok" << endl;
    init_signal_slot();//initialize signals and slots
    //std::cout << "init signal & slot ok" << endl;
}

RS_DEMO_GDAL::~RS_DEMO_GDAL()
{
    delete ui;
}
void RS_DEMO_GDAL::init_ui()
{
    errordlg = new QErrorMessage(this);

//    filetoolarge = new FileTooLarge;
    //menu bar init
    menu_file = (ui->menuBar)->addMenu(QString::fromLocal8Bit("文件"));
    act_open = menu_file->addAction(QString::fromLocal8Bit("打开"));
    act_open->setShortcut(QKeySequence::Open);
    act_save = menu_file->addAction(QString::fromLocal8Bit("保存"));
    act_save->setShortcut(QKeySequence::Save);

    ui->mainToolBar->addAction(act_open);

    //主要区域的初始化
    widget_center = new QWidget(this);
    setCentralWidget(widget_center);

    //状态句柄
    status = new QLabel;

    //信息栏


    //图片浏览
    view_wid_origin = new QWidget(widget_center);
    view_wid_after = new QWidget(widget_center);
    QWidget* tmp1 = new QWidget(view_wid_origin);
    tmp1->setFixedSize(30,30);
    QWidget* tmp2 = new QWidget(view_wid_after);
    tmp2->setFixedSize(30,30);

    QVBoxLayout* view_layout_origin = new QVBoxLayout;
    QHBoxLayout* templayout1 = new QHBoxLayout;
    templayout1->addWidget(tmp1);

    templayout1->setSpacing(0);
    QHBoxLayout* view_hlayout_origin = new QHBoxLayout;

    view_hlayout_origin->setSpacing(0);
    view_layout_origin->addLayout(templayout1);
    view_layout_origin->addLayout(view_hlayout_origin);
    view_layout_origin->setSpacing(0);
    view_wid_origin->setLayout(view_layout_origin);

    //layout
    layout_main = new QVBoxLayout;
    layout_up = new QHBoxLayout;
    layout_down = new QHBoxLayout;

    layout_up->addWidget(view_wid_origin);
    layout_up->addWidget(view_wid_after);

    layout_main->addLayout(layout_up);

    layout_main->setStretchFactor(layout_up,8);
    layout_main->setStretchFactor(layout_down,2);
    widget_center->setLayout(layout_main);
}

void RS_DEMO_GDAL::init_signal_slot()
{
    connect(act_open,SIGNAL(triggered(bool)),this,SLOT(open()));
}

void RS_DEMO_GDAL::open()
{
    clockid_t clockBegin,clockEnd;
    qfilename = QFileDialog::getOpenFileName(this,"Open Image File",QString(),
                                             "Image FIles (*,jpg *.bmp *.tif *.tiff *.png *.img *.int):: All Fils(*.*)");
    std::string filename = qfilename.toStdString();
    clockBegin = clock();

    QProgressDialog opendialog(QString::fromLocal8Bit("文件载入中"),
                               QString::fromLocal8Bit("知道了"),0,3000,this);
    opendialog.setWindowTitle(QString::fromLocal8Bit("文件载入中"));
    opendialog.setWindowModality(Qt::WindowModal);
    opendialog.show();

    GDALAllRegister();
    pDataOri = (GDALDataset*)GDALOpen(filename.c_str(),GA_ReadOnly);
    opendialog.setValue(1000);
    QCoreApplication::processEvents();

    if(pDataOri){
        std::cout << "打开文件成功" << std::endl;
    }
}
