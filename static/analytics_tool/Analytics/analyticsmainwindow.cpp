/*
#include "analyticsmainwindow.h"
#include "ui_analyticsmainwindow.h"

AnalyticsMainWindow::AnalyticsMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalyticsMainWindow)
{
    ui->setupUi(this);
}

AnalyticsMainWindow::~AnalyticsMainWindow()
{
    delete ui;
}
*/


/// sabbir

#include "analyticsmainwindow.h"
#include "ui_analyticsmainwindow.h"
#include <QDebug>
//#include <Analytics/soapDeviceBindingProxy.h>
//#include <Analytics/soapMediaBindingProxy.h>
//#include <Analytics/wsseapi.h>
//#include <Analytics/wsaapi.h>
//#include "soapH.h"
//#include "soapRemoteDiscoveryBindingProxy.h"
//#include "soapPTZBindingProxy.h"
//#include "soapPullPointSubscriptionBindingProxy.h"
//#include  "ErrorLog.h"
//#include <bits/stdc++.h>
#include <QMediaPlayer>
#include <QNetworkRequest>
#include <bits/stdc++.h>
#include <QMessageBox>
//#include <Analytics/smdevp.h>

using namespace std;
//int ptzability=-1,src=0;
//unordered_map<string,bool>mp;
//int pre = 0,devider=0,ptZ=0;
//stringstream ss ;
//std::string sss;
QStringList str2,str3;

//PTZBindingProxy proxyPTZ;
//_tptz__RelativeMove ptz_req;
//_tptz__RelativeMoveResponse ptz_resp;
//std::string strMediaAddr;
//std::string strProfileToken;
//tt__Vector1D* zoom = (struct tt__Vector1D *)soap_new_tt__Vector1D(proxyPTZ.soap, -1);
//std::string str="http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace";
//std::string str2 ="http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace";
//int result = 0;
//PTZBindingProxy proxyPTZ;
//_tptz__RelativeMove ptz_req;
//_tptz__RelativeMoveResponse ptz_resp;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define RIGHTUPPERCORNER 8
#define RIGHTLOWERCORNER 9
#define LEFTUPPERCORNER 6
#define LEFTLOWERCORNER 7
#define ZOOMIN 4
#define ZOOMOUT 5
#define speed 1
#define sp 10
//QString array[10]={"1","2"};

AnalyticsMainWindow::AnalyticsMainWindow(QWidget *parent) :QWidget(parent),ui(new Ui::AnalyticsMainWindow)
{
//    int  _metadataVersion = 1;
//    char* _xaddr="http://localhost/service";
//    char* _type="\"http://schemas.xmlsoap.org/ws/2006/02/devprof\":device";
//    char* _scope="scope";
//    char* _endpoint="urn";


//    discoveryObj = new DiscoveryObj(CLIENT_MODE, _metadataVersion, _xaddr, _type, _scope, _endpoint);
//    connect(discoveryObj,SIGNAL(discoveredDevice(DescDevice)) ,this,SLOT(onDiscoveredDevice(DescDevice)));
    //    connect(this,SIGNAL(warned()) ,this,SLOT(onWarned()));
    ui->setupUi(this);

    //timer = new QTimer;
    //connect(timer,SIGNAL(timeout()),this,SLOT(slider_delay()));


    mediaPlayer = new QMediaPlayer(this);
    videoItem = new QGraphicsVideoItem;
    scene = new QGraphicsScene(this);
    graphicsView = new MyGraphicsView();


    graphicsView->setScene(scene);

    mediaPlayer->setVideoOutput(videoItem);
    graphicsView->scene()->addItem(videoItem);
    graphicsView->show();

    QSize videoSize = graphicsView->size();
    videoItem->setSize(videoSize);

    ui->horizontalLayout->addWidget(graphicsView);

    ui->DrawRect->setCheckable(true);
    ui->DrawLine->setCheckable(true);


    //    graphicsView = new MyGraphicsView();
    //    mediaPlayer = new QMediaPlayer(this);
    //    videoItem = new QGraphicsVideoItem;
    //    scene = new QGraphicsScene(this);
    //    scene->setBackgroundBrush(Qt::black);

    //    videoSize.setHeight(329);
    //    videoSize.setWidth(534);
    //    videoItem->setSize(videoSize);
    //    graphicsView->setScene(scene);
    //    mediaPlayer->setVideoOutput(videoItem);
    //    graphicsView->scene()->addItem(videoItem);
    //    graphicsView->show();
    //    ui->horizontalLayout->addWidget(graphicsView);

//    QPixmap pixmap("./resources/icon/zoom-in-button.png");
//    QIcon ButtonIcon(pixmap);
//    ui->ZoomIn->setIcon(ButtonIcon);
//    ui->ZoomIn->setIconSize(QSize(20, 30));
//    ui->ZoomIn->setFixedSize(QSize(30, 30));

//    QPixmap pixmap1("./resources/icon/zoom-out.png");
//    QIcon ButtonIcon1(pixmap1);
//    ui->ZoomOut->setIcon(ButtonIcon1);
//    ui->ZoomOut->setIconSize(QSize(20, 30));
//    ui->ZoomOut->setFixedSize(QSize(30, 30));

//    QPixmap pixmap2("./resources/icon/play-button(2).png");
//    QIcon ButtonIcon2(pixmap2);
//    ui->left->setIcon(ButtonIcon2);
//    ui->left->setIconSize(QSize(20, 30));
//    ui->left->setFixedSize(QSize(30, 30));

//    QPixmap pixmap3("./resources/icon/play-button(2) (another copy).png");
//    QIcon ButtonIcon3(pixmap3);
//    ui->down->setIcon(ButtonIcon3);
//    ui->down->setIconSize(QSize(20, 30));
//    ui->down->setFixedSize(QSize(30, 30));

//    QPixmap pixmap4("./resources/icon/play-button(2) (copy).png");
//    QIcon ButtonIcon4(pixmap4);
//    ui->up->setIcon(ButtonIcon4);
//    ui->up->setIconSize(QSize(20, 30));
//    ui->up->setFixedSize(QSize(30, 30));

//    QPixmap pixmap5("./resources/icon/play-button(2) (3rd copy).png");
//    QIcon ButtonIcon5(pixmap5);
//    ui->right->setIcon(ButtonIcon5);
//    ui->right->setIconSize(QSize(20, 30));
//    ui->right->setFixedSize(QSize(30, 30));

//    QPixmap pixmap6("./resources/icon/diagonal-arrow (copy).png");
//    QIcon ButtonIcon6(pixmap6);
//    ui->leftupper->setIcon(ButtonIcon6);
//    ui->leftupper->setIconSize(QSize(16, 26));
//    ui->leftupper->setFixedSize(QSize(30, 30));

//    QPixmap pixmap7("./resources/icon/diagonal-arrow.png");
//    QIcon ButtonIcon7(pixmap7);
//    ui->leftlower->setIcon(ButtonIcon7);
//    ui->leftlower->setIconSize(QSize(16, 26));
//    ui->leftlower->setFixedSize(QSize(30, 30));

//    QPixmap pixmap8("./resources/icon/diagonal-arrow (another copy).png");
//    QIcon ButtonIcon8(pixmap8);
//    ui->rightupper->setIcon(ButtonIcon8);
//    ui->rightupper->setIconSize(QSize(16, 26));
//    ui->rightupper->setFixedSize(QSize(30, 30));

//    QPixmap pixmap9("./resources/icon/diagonal-arrow (3rd copy).png");
//    QIcon ButtonIcon9(pixmap9);
//    ui->rightlower->setIcon(ButtonIcon9);
//    ui->rightlower->setIconSize(QSize(16, 26));
//    ui->rightlower->setFixedSize(QSize(30, 30));

//    QPixmap pixmap10("./resources/icon/button.png");
//    QIcon ButtonIcon10(pixmap10);
//    ui->middle_circle->setIcon(ButtonIcon10);
//    ui->middle_circle->setIconSize(QSize(20, 30));
//    ui->middle_circle->setFixedSize(QSize(30, 30));

//    ui->display_video->setEnabled(false);
//    //ui->pushButton_add->setEnabled(false);
//    //ui->label_header->setStyleSheet("QLabel{font-size: 18pt;font-weight: bold;}");

//    ui->ZoomIn->setAutoRepeat(true);
//    ui->ZoomOut->setAutoRepeat(true);
//    ui->up->setAutoRepeat(true);
//    ui->down->setAutoRepeat(true);
//    ui->left->setAutoRepeat(true);
//    ui->right->setAutoRepeat(true);
//    ui->rightupper->setAutoRepeat(true);
//    ui->rightlower->setAutoRepeat(true);
//    ui->leftupper->setAutoRepeat(true);
//    ui->leftlower->setAutoRepeat(true);

//    ui->rightlower->setStyleSheet(
//                "border: 1px solid dimgray;"
//                "border-bottom-right-radius: 15px;"
//                );
//    ui->rightupper->setStyleSheet(
//                "border: 1px solid dimgray;"
//                "border-top-right-radius: 15px;"
//                );
//    ui->leftupper->setStyleSheet(
//                "border: 1px solid dimgray;"
//                "border-top-left-radius: 15px;"
//                );
//    ui->leftlower->setStyleSheet(
//                "border: 1px solid dimgray;"
//                "border-bottom-left-radius: 15px;"
//                );
//    ui->left->setStyleSheet(
//                "border: 1px solid dimgray;"
//                );
//    ui->right->setStyleSheet(
//                "border: 1px solid dimgray;"
//                );
//    ui->up->setStyleSheet(
//                "border: 1px solid dimgray;"
//                );
//    ui->down->setStyleSheet(
//                "border: 1px solid dimgray;"
//                );
//    ui->middle_circle->setStyleSheet(
//                "border: 1px solid dimgray;"
//                );

    ui->DrawRect->setIcon(QIcon("./resources/icon/drawrect.svg"));
    ui->DrawLine->setIcon(QIcon("./resources/icon/drawline.svg"));
    ui->SetDrawing->setIcon(QIcon("./resources/icon/setdrawing.svg"));
    ui->ClearDrawing->setIcon(QIcon("./resources/icon/remove.svg"));
    ui->lc_mode_entry_cb->setIcon(QIcon("./resources/icon/entry.svg"));
    ui->lc_mode_exit_cb->setIcon(QIcon("./resources/icon/exit.svg"));

    loadFromTextFile();
    TemplateforSourecFile();

    if(!checkClassValidity(0)) ui->label_14->show();
    else ui->label_14->hide();

    if(!checkClassValidity(1)) ui->label_15->show();
    else ui->label_15->hide();

    //connect(ui->Zoom,SIGNAL(valueChanged(int)), this,SLOT(slotSetValue(int)));
}

AnalyticsMainWindow::~AnalyticsMainWindow()
{
    delete ui;
}

//void AnalyticsMainWindow::onDiscoveredDevice(DescDevice dev)
//{

//}

//void AnalyticsMainWindow::on_btnSendProb_clicked()
//{
//    discoveryObj->sendProb();
//}

//void AnalyticsMainWindow::on_pushButton_login_clicked()
//{
//    ui->display_video->setEnabled(false);

//    m_passwd = Password.toStdString();

//    m_username = Username.toStdString();


//    std::string IP1 = m_deviceurl;
//    ip_address = "",port="";

//    for( int i = 0 ; i <(int) IP1.size() ; i++)
//    {
//        if(IP1[i]==':')
//        {
//            for( i = i+3 ; i <(int) IP1.size() ; i++)
//            {
//                if(IP1[i]=='/') break;
//                ip_address+=IP1[i];
//            }
//            break;
//        }
//    }
//    IP_add  = QString::fromStdString( ip_address );

//    char ipHostName[128] = { 0 };
//    strcat(ipHostName, "http://");
//    strcat(ipHostName, ip_address.c_str());
//    strcat(ipHostName, "/onvif/device_service");

//    rtsp_url = "";
//    //rtsp://192.168.0.109:554/cam/realmonitor?channel=1&subtype=0&unicast=true&proto=Onvi
//    if(getRTSPUrl(ipHostName,rtsp_url)!=-1)
//    {
//        ui->display_video->setEnabled(true);

//        for( int i = 0 ,cnt=0; i <(int) rtsp_url.size() ; i++)
//        {
//            if(rtsp_url[i]==':') cnt++;
//            if(cnt==2)
//            {
//                for( i = i+1 ;  i <(int) rtsp_url.size() ; i++)
//                {
//                    if(rtsp_url[i]=='/') break;
//                    port+=rtsp_url[i];
//                }
//                break;
//            }
//        }
//    }
//    ui->lineEdit_rtsp->setText(QString::fromStdString(rtsp_url));
//}


//int AnalyticsMainWindow::getRTSPUrl(const char*mediaAddr,string&rtspUrl){
//    if(mediaAddr==NULL){
//        return -1;
//    }
//    MediaBindingProxy proxyMedia;
//    proxyMedia.soap_endpoint = mediaAddr;
//    soap_register_plugin(proxyMedia.soap, soap_wsse);
//    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(proxyMedia.soap, NULL, m_username.c_str(), m_passwd.c_str()))
//    {
//        rtspUrl = "Wrong Username or Password";
//        return -1;
//    }

//    tt__Transport               transport;
//    transport.Tunnel = NULL;
//    transport.Protocol = tt__TransportProtocol__RTSP;

//    tt__StreamSetup             setup;
//    setup.Transport = &transport;
//    setup.Stream = tt__StreamType__RTP_Unicast;

//    _trt__GetStreamUri          StreamUri_req;
//    _trt__GetStreamUriResponse  StreamUri_rep;

//    StreamUri_req.StreamSetup = &setup;

//    string profileToken;
//    getProfile(mediaAddr,profileToken);
//    StreamUri_req.ProfileToken = profileToken;


//    int result = proxyMedia.GetStreamUri(mediaAddr, NULL, &StreamUri_req, &StreamUri_rep);
//    if (SOAP_OK != result)
//    {
//        rtspUrl="GetStreamUri error";
//        return -1;
//    }
//    rtspUrl = StreamUri_rep.MediaUri->Uri;
//    return SOAP_OK;
//}

//int AnalyticsMainWindow::getProfile(const char*mediaAddr,string&profileToken){
//    if(mediaAddr==NULL){
//        return -1;
//    }
//    MediaBindingProxy proxyMedia;
//    proxyMedia.soap_endpoint = mediaAddr;
//    soap_register_plugin(proxyMedia.soap, soap_wsse);
//    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(proxyMedia.soap, NULL, m_username.c_str(), m_passwd.c_str()))
//    {
//        profileToken = "Wrong Username or Password";
//        return -1;
//    }
//    _trt__GetProfiles           Profiles_req;
//    _trt__GetProfilesResponse   Profiles_rep;
//    int result = proxyMedia.GetProfiles(mediaAddr, NULL, &Profiles_req, &Profiles_rep);
//    if (SOAP_OK != result)
//    {
//        profileToken="GetProfiles error.";
//        return -1;
//    }
//    profileToken = Profiles_rep.Profiles[0]->token;
//    return SOAP_OK;
//}


void AnalyticsMainWindow::on_display_video_clicked()
{
    //    //ptz();
    //    ptzability=-1;
    //    //ui->pushButton_add->setEnabled(true);
    //    rtsp = ui->lineEdit_rtsp->text().toStdString();
    //    Table_rtsp = QString::fromStdString(rtsp);
    //    std::string username_pass = m_username+":"+m_passwd+"@";
    //    rtsp.insert(7,username_pass);
    //    RTSP = QString::fromStdString(rtsp);
    //    qDebug()<<RTSP;
    //    graphicsView->close();
    //    graphicsView = new MyGraphicsView();

    //    graphicsView->setScene(scene);
    //    graphicsView->scene()->addItem(videoItem);
    //    graphicsView->show();
    //    ui->horizontalLayout->addWidget(graphicsView);

    //    const QUrl url1 = QUrl(RTSP);
    //    const QNetworkRequest requestRtsp1(url1);
    //    mediaPlayer->stop();
    //    mediaPlayer->setMedia(requestRtsp1);
    //    mediaPlayer->play();
    //    ptzability=1;

    graphicsView->update();
    graphicsView->point.saved_line_points.clear();
    graphicsView->point.saved_rect_points.clear();


    rtsp = ui->lineEdit_rtsp->text().toStdString();
    Table_rtsp = QString::fromStdString(rtsp);
    RTSP = QString::fromStdString(rtsp);

    const QUrl url1 = QUrl(RTSP);
    const QNetworkRequest requestRtsp1(url1);
    mediaPlayer->stop();
    mediaPlayer->setMedia(requestRtsp1);
    mediaPlayer->play();


    QSize videoSize = graphicsView->size();
    videoItem->setSize(videoSize);
    qDebug() <<"on display video size: "<< videoSize;

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();


}



//int AnalyticsMainWindow:: DeviceInformation(char*szHostName,QString &Device_INFO)
//{
//    DeviceBindingProxy proxyDevice;
//    proxyDevice.soap_endpoint = szHostName;
//    soap_register_plugin(proxyDevice.soap, soap_wsse);
//    struct soap *soap = soap_new();
//    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(proxyDevice.soap, NULL, m_username.c_str(), m_passwd.c_str()))
//    {
//        Device_INFO = "Wrong Username or Password";
//        return -1;
//    }
//    _tds__GetDeviceInformation *tds__GetDeviceInformation = soap_new__tds__GetDeviceInformation(soap, -1);
//    _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse = soap_new__tds__GetDeviceInformationResponse(soap, -1);
//    if (SOAP_OK == proxyDevice.GetDeviceInformation(tds__GetDeviceInformation, tds__GetDeviceInformationResponse))
//    {
//        QString Manufacturer =QString::fromStdString(tds__GetDeviceInformationResponse->Manufacturer);
//        QString Model =QString::fromStdString(tds__GetDeviceInformationResponse->Model);
//        QString FirmwareVersion =QString::fromStdString(tds__GetDeviceInformationResponse->FirmwareVersion);
//        QString SerialNumber =QString::fromStdString(tds__GetDeviceInformationResponse->SerialNumber);
//        QString HardwareId =QString::fromStdString(tds__GetDeviceInformationResponse->HardwareId);
//        Device_INFO = QString("Manufacturer : "+Manufacturer+", "+"Model : "+Model+", "+"FirmwareVersion : "+FirmwareVersion+", "+
//                              "SerialNumber : "+SerialNumber+", "+"HardwareId : "+HardwareId+"\n");
//    }
//    else
//    {
//        Device_INFO = "Device Information Error";
//    }
//    soap_destroy(soap);
//    soap_end(soap);
//    return 0;
//}

//void AnalyticsMainWindow::on_pushButton_add_clicked()
//{
//        //ui->pushButton_add->setEnabled(false);
//        if(mp.count(ip_address)) return;
//        editSourceNumber();
//        src++;
//        mp[ip_address]=true;

//        Device_INFO = "";
//        char ipHostName[128] = { 0 };
//        strcat(ipHostName, "http://");
//        strcat(ipHostName, ip_address.c_str());
//        strcat(ipHostName, "/onvif/device_service");
//        DeviceInformation(ipHostName,Device_INFO);

//}



//int AnalyticsMainWindow::getMediaUrl(string& mediaAddr){
//    DeviceBindingProxy proxyDevice;
//    proxyDevice.soap_endpoint = m_deviceurl.c_str();

//    soap_register_plugin(proxyDevice.soap, soap_wsse);
//    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(proxyDevice.soap, NULL, m_username.c_str(), m_passwd.c_str()))
//    {
//        mediaAddr = "Wrong Username or Password";
//        return -1;
//    }
//    _tds__GetCapabilities           Bilities_req;
//    _tds__GetCapabilitiesResponse   Bilities_rep;
//    int result = proxyDevice.GetCapabilities(m_deviceurl.c_str(), NULL, &Bilities_req, &Bilities_rep);

//    if (SOAP_OK != result)
//    {
//        mediaAddr="GetCapabilities error";
//        return -1;
//    }
//    else{
//        if (Bilities_rep.Capabilities == NULL || Bilities_rep.Capabilities->Media == NULL)
//        {
//            mediaAddr="no capability";
//            return -1;
//        }
//    }
//    mediaAddr = Bilities_rep.Capabilities->Media->XAddr;
//    return SOAP_OK;
//}
//int AnalyticsMainWindow::ptz()
//{

    //        proxyPTZ.soap_endpoint = m_deviceurl.c_str();

    //        result = getMediaUrl(strMediaAddr);
    //        if (result!=SOAP_OK){
    //            return -1;
    //        }

    //        result = getProfile(strMediaAddr.c_str(), strProfileToken);
    //        if (result!=SOAP_OK){
    //            return -1;
    //        }

    //        soap_register_plugin(proxyPTZ.soap, soap_wsse);
    //        if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(proxyPTZ.soap, NULL, m_username.c_str(), m_passwd.c_str()))
    //        {
    //            return -1;
    //        }

    //        //memset(&ptz_req, 0x0, sizeof(ptz_req));
    //        //memset(&ptz_resp, 0x0, sizeof(ptz_resp));

    //        ptz_req.ProfileToken = strProfileToken;
    //        ptz_req.Speed = soap_new_tt__PTZSpeed(proxyPTZ.soap, -1);;
    //        //memset(ptz_req.Translation, 0x0, sizeof(tt__PTZVector));
    //        ptz_req.Speed->PanTilt = (struct tt__Vector2D *)soap_new_tt__Vector2D(proxyPTZ.soap, -1);
    //        //memset(ptz_req.Translation->PanTilt, 0x0, sizeof(tt__Vector2D));
    //        //std::string str="http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace";
    //        //ptz_req.Translation->PanTilt->space =&str;
    //        ptz_req.Translation = soap_new_tt__PTZVector(proxyPTZ.soap, -1);
    //        ptz_req.Translation->PanTilt = (struct tt__Vector2D *)soap_new_tt__Vector2D(proxyPTZ.soap, -1);
    //        zoom = (struct tt__Vector1D *)soap_new_tt__Vector1D(proxyPTZ.soap, -1);
    //        ptz_req.Translation->Zoom = zoom;
    //        ptz_req.Translation->PanTilt->space =&str;
    //        ptz_req.Translation->Zoom->space = &str2;
    //        //memset(ptz_req.Translation->Zoom, 0x0, sizeof(tt__Vector1D));

//}

//int AnalyticsMainWindow::ptzRelativeMove(/*const char* deviceAddr,*/int command)
//{
//    sss = QString(ui->movement_step->currentText()).toStdString();
//    ss.clear();
//    ss<<sss;
//    ss>>devider;
//    PTZBindingProxy proxyPTZ;
//    proxyPTZ.soap_endpoint = m_deviceurl.c_str();

//    std::string strMediaAddr;
//    int result = 0;
//    result = getMediaUrl(strMediaAddr);
//    if (result!=SOAP_OK){
//        return -1;
//    }
//    std::string strProfileToken;
//    result = getProfile(strMediaAddr.c_str(), strProfileToken);
//    if (result!=SOAP_OK){
//        return -1;
//    }

//    soap_register_plugin(proxyPTZ.soap, soap_wsse);
//    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(proxyPTZ.soap, NULL, m_username.c_str(), m_passwd.c_str()))
//    {
//        return -1;
//    }
//    _tptz__RelativeMove ptz_req;
//    _tptz__RelativeMoveResponse ptz_resp;
//    //memset(&ptz_req, 0x0, sizeof(ptz_req));
//    //memset(&ptz_resp, 0x0, sizeof(ptz_resp));

//    ptz_req.ProfileToken = strProfileToken;
//    ptz_req.Speed = soap_new_tt__PTZSpeed(proxyPTZ.soap, -1);;
//    //memset(ptz_req.Translation, 0x0, sizeof(tt__PTZVector));
//    ptz_req.Speed->PanTilt = (struct tt__Vector2D *)soap_new_tt__Vector2D(proxyPTZ.soap, -1);
//    //memset(ptz_req.Translation->PanTilt, 0x0, sizeof(tt__Vector2D));
//    //std::string str="http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace";
//    //ptz_req.Translation->PanTilt->space =&str;
//    ptz_req.Translation = soap_new_tt__PTZVector(proxyPTZ.soap, -1);
//    ptz_req.Translation->PanTilt = (struct tt__Vector2D *)soap_new_tt__Vector2D(proxyPTZ.soap, -1);
//    tt__Vector1D* zoom = (struct tt__Vector1D *)soap_new_tt__Vector1D(proxyPTZ.soap, -1);
//    ptz_req.Translation->Zoom = zoom;
//    std::string str="http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace";
//    ptz_req.Translation->PanTilt->space =&str;
//    std::string str2 ="http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace";
//    ptz_req.Translation->Zoom->space = &str2;
//    //memset(ptz_req.Translation->Zoom, 0x0, sizeof(tt__Vector1D));
//    int d=100-devider;
//    //devider=10;
//    std::cout<<d<<endl;
//    //devider=10;
//    switch (command)
//    {

//    case RIGHTUPPERCORNER:
//        //ptz_req.Speed->PanTilt->x = -((float)speed / 10);
//        ptz_req.Translation->PanTilt->x = ((float)speed / d);
//        ptz_req.Translation->PanTilt->y = ((float)speed / d);
//        break;
//    case RIGHTLOWERCORNER:
//        //ptz_req.Speed->PanTilt->x = -((float)speed / 10);
//        ptz_req.Translation->PanTilt->x = ((float)speed / d);
//        ptz_req.Translation->PanTilt->y = -((float)speed / d);
//        break;
//    case LEFTUPPERCORNER:
//        //ptz_req.Speed->PanTilt->x = -((float)speed / 10);
//        ptz_req.Translation->PanTilt->x = -((float)speed / d);
//        ptz_req.Translation->PanTilt->y = ((float)speed / d);
//        break;
//    case LEFTLOWERCORNER:
//        //ptz_req.Speed->PanTilt->x = -((float)speed / 10);
//        ptz_req.Translation->PanTilt->x = -((float)speed / d);
//        ptz_req.Translation->PanTilt->y = -((float)speed / d);
//        break;
//    case LEFT:
//        //ptz_req.Speed->PanTilt->x = -((float)speed / 10);
//        ptz_req.Translation->PanTilt->x = -((float)speed / d);
//        ptz_req.Translation->PanTilt->y = 0;
//        break;
//    case RIGHT:
//        //ptz_req.Speed->PanTilt->x = ((float)speed / 10);
//        ptz_req.Translation->PanTilt->x = ((float)speed / d);
//        ptz_req.Translation->PanTilt->y = 0;
//        break;
//    case sp:
//        ptz_req.Speed->PanTilt->x =1.0;
//        //ptz_req.Translation->PanTilt->x = 0;
//        ptz_req.Speed->PanTilt->y = ((float)speed / d);
//        //ptz_req.Translation->PanTilt->y = ((float)speed / d);
//    case UP:
//        ptz_req.Translation->PanTilt->x = 0;
//        //ptz_req.Speed->PanTilt->y = ((float)speed / 10);
//        ptz_req.Translation->PanTilt->y = ((float)speed / d);
//        break;
//    case DOWN:
//        ptz_req.Translation->PanTilt->x = 0;
//        //ptz_req.Speed->PanTilt->y = -((float)speed / 10);
//        ptz_req.Translation->PanTilt->y = -((float)speed / d);
//        break;
//    case ZOOMIN:
//        ptz_req.Translation->Zoom->x = .00001;
//        break;
//    case ZOOMOUT:
//        ptz_req.Translation->Zoom->x = -.00001;
//        break;
//    default:
//        break;
//    }
//    if (proxyPTZ.RelativeMove(proxyPTZ.soap_endpoint,NULL,&ptz_req, &ptz_resp) == SOAP_OK)
//        //std::cout<<"\nsuccess\n";
//        return 0;
//    else
//        //std::cout<<"\nfail\n";
//        return -1;
//}


//int AnalyticsMainWindow::ptzContinuousMove(/*const char* deviceAddr,*/int command)
//{

//    PTZBindingProxy proxyPTZ;
//    proxyPTZ.soap_endpoint = m_deviceurl.c_str();

//    std::string strMediaAddr;
//    int result = 0;
//    result = getMediaUrl(strMediaAddr);
//    if (result!=SOAP_OK){
//        return -1;
//    }
//    std::string strProfileToken;
//    result = getProfile(strMediaAddr.c_str(), strProfileToken);
//    if (result!=SOAP_OK){
//        return -1;
//    }

//    soap_register_plugin(proxyPTZ.soap, soap_wsse);
//    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(proxyPTZ.soap, NULL,  m_username.c_str(), m_passwd.c_str()))
//    {
//        return -1;
//    }

//    _tptz__ContinuousMove continuousMove;// = soap_new__tptz__ContinuousMove(proxyDevice.soap, -1);
//    _tptz__ContinuousMoveResponse response;// = soap_new__tptz__ContinuousMoveResponse(proxyDevice.soap, -1);
//    continuousMove.ProfileToken = const_cast<char *>(strProfileToken.c_str());
//    tt__PTZSpeed* velocity = soap_new_tt__PTZSpeed(proxyPTZ.soap, -1);
//    continuousMove.Velocity = velocity;
//    tt__Vector2D* panTilt = soap_new_tt__Vector2D(proxyPTZ.soap, -1);
//    continuousMove.Velocity->PanTilt = panTilt;
//    std::string str="http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace";
//    continuousMove.Velocity->PanTilt->space =&str;
//    tt__Vector1D* zoom = soap_new_tt__Vector1D(proxyPTZ.soap, -1);
//    continuousMove.Velocity->Zoom = zoom;
//    //continuousMove.Velocity->PanTilt->x=optio
//    switch (command)
//    {
//    case LEFT:
//        continuousMove.Velocity->PanTilt->x = -((float)speed / 10);
//        continuousMove.Velocity->PanTilt->y = 0;
//        break;
//    case RIGHT:
//        continuousMove.Velocity->PanTilt->x = ((float)speed / 10);
//        continuousMove.Velocity->PanTilt->y = 0;
//        break;
//    case UP:
//        continuousMove.Velocity->PanTilt->x = 0;
//        continuousMove.Velocity->PanTilt->y = ((float)speed / 10);
//        break;
//    case DOWN:
//        continuousMove.Velocity->PanTilt->x = 0;
//        continuousMove.Velocity->PanTilt->y = -((float)speed / 10);
//        break;
//    case ZOOMIN:
//        continuousMove.Velocity->Zoom->x = -((float)speed / 10);
//        break;
//    case ZOOMOUT:
//        continuousMove.Velocity->Zoom->x = -((float)speed / 10);
//        break;
//    default:
//        ptZ=0;
//        break;
//    }
//    //wait for test
//    if (proxyPTZ.ContinuousMove(proxyPTZ.soap_endpoint,NULL,&continuousMove, &response) == SOAP_OK)
//        //std::cout<<"\nsuccess\n";
//        return 0;
//    else
//        //std::cout<<"\nfail\n";
//        return -1;
//}




//void AnalyticsMainWindow::on_right_clicked()
//{
//    if(ptZ!=-1) ptzRelativeMove(3);
//    //ptzContinuousMove(3);
//}

//void AnalyticsMainWindow::on_left_clicked()
//{
//    if(ptZ!=-1)ptzRelativeMove(2);
//    //ptzContinuousMove(2);
//}

//void AnalyticsMainWindow::on_down_clicked()
//{
//    if(ptZ!=-1)ptzRelativeMove(1);
//    //ptzContinuousMove(1);
//}

//void AnalyticsMainWindow::on_up_clicked()
//{
//    if(ptZ!=-1) ptzRelativeMove(0);
//    //ptzContinuousMove(0);
//}

//void AnalyticsMainWindow::on_ZoomIn_clicked()
//{
//    if(ptZ!=-1)ptzRelativeMove(4);
//    //ptzContinuousMove(4);
//}

//void AnalyticsMainWindow::on_ZoomOut_clicked()
//{
//    if(ptZ!=-1)ptzRelativeMove(5);
//    //ptzContinuousMove(5);
//}

//void AnalyticsMainWindow::on_leftupper_clicked()
//{
//    if(ptZ!=-1)ptzRelativeMove(6);
//}

//void AnalyticsMainWindow::on_leftlower_clicked()
//{
//    if(ptZ!=-1) ptzRelativeMove(7);
//}

//void AnalyticsMainWindow::on_rightupper_clicked()
//{
//    if(ptZ!=-1)ptzRelativeMove(8);
//}

//void AnalyticsMainWindow::on_rightlower_clicked()
//{
//    cout<<"ptZ = "<<ptZ<<endl;
//    if(ptZ!=-1)ptzRelativeMove(9);
//}

//void AnalyticsMainWindow::on_speed_clicked()
//{
//    if(ptZ!=-1)ptzRelativeMove(10);
//}

void AnalyticsMainWindow::loadFromTextFile()
{
    // camera list
    qDebug() << "Camera list" << endl;
    ui->display_video->setEnabled(true);
    
    QFile input_file("/home/sigmind/analytics_tool_sabbir/resources/cfg/deepstream_app_source1_peoplenet.txt");

    if(input_file.open(QIODevice::ReadOnly)){

        QTextStream in(&input_file);

        int source_number = 0;
        QString source = "[source"+QString::number(source_number)+"]";

        while(!in.atEnd()){

            QString line = in.readLine();
            str3.append(line);

            if(line.contains("#")) continue;
            if(line == source){
                qDebug()<<"if : " <<source;

                ++source_number;

            }

            if(line.contains("uri="))
            {
                QString uri = line.mid(line.indexOf("uri=")+4,line.size());
                rtspURLs.append(uri);
                ui->comboBox->addItem("[source"+QString::number(source_number - 1)+"]");
            }

            source = "[source"+QString::number(source_number)+"]";
        }
        input_file.close();
    }

}

void AnalyticsMainWindow::TemplateforSourecFile()
{

    //    QFile input_file("./resources/cfg/deepstream_app_source1_peoplenet.txt");
    QFile input_file("./cfg/deepstream-app/deepstream_app_source1_peoplenet.txt");

    if(input_file.open(QIODevice::ReadOnly)){

        QTextStream in(&input_file);

        int source_number = 0;
        QString source = "[source"+QString::number(source_number)+"]";
        str2.append("\n");
        while(!in.atEnd()){

            QString line = in.readLine();
            if(line == source){
                str2.append(line);
                for( int ii = 1 ; ii<=31 ; ii++) {
                    line = in.readLine();
                    str2.append(line);
                }
            }

        }
        input_file.close();
    }

}
//void AnalyticsMainWindow::editSourceNumber(){
//    QFile input_file("./resources/cfg/deepstream_app_source1_peoplenet.txt");
//    if (!input_file.open(QFile::WriteOnly)) {
//        //qDebug() << "Error opening for write: " << input_file.errorString();
//        return;
//    }
//    QTextStream outStream(&input_file);
//    for(int i = 0; i < str3.size(); i++){
//        outStream << str3[i]<<"\n";
//    }
//    str2[1][7]=src+'0';
//    for(int i = 0; i < str2.size(); i++){
//        outStream << str2[i]<<"\n";
//        str3.append(str2[i]);
//    }
//    input_file.close();
//}


QString AnalyticsMainWindow::read_nvdsanalytics_cfg()
{
    QFile input_file("/home/sigmind/analytics_tool_sabbir/resources/cfg/config_nvdsanalytics_htpa.txt");

    input_file.open(QIODevice::ReadOnly);

    QTextStream in(&input_file);

    QString cfg_data = in.readAll();
    input_file.close();

    return cfg_data;
}

void AnalyticsMainWindow::edit_nvdsanalytics_cfg(QString pattern, QString property, QString subproperty)
{

    int parentfirst = cfg_data.indexOf(property) + property.length();
    int parentlast = end_indexof(cfg_data, parentfirst, "\n[", 0);

    QString substring = cfg_data.mid(parentfirst, parentlast-parentfirst);
    int substring_length = substring.length();

    int j = 0;
    int found = 0;

    qDebug()<<"search in substring:: "<< substring;
    // Search weather subproperty is already present
    while ((j = substring.indexOf(subproperty, j)) != -1) {
        qDebug()<< "Found" << subproperty << "at index " << j;
        found = 1;
        ++j;
    }

    if(found)
       replace_data(substring, pattern, subproperty, parentfirst);
    else
    {
        substring.append(subproperty + pattern + "\n");
        cfg_data.replace(parentfirst, substring_length, substring);
    }


}

int AnalyticsMainWindow::end_indexof(QString mainString, int first, QString endString, int initial_index)
{
    int last;
    for (int i = 0; i < mainString.length(); i++) {
        if (mainString.mid(i, endString.length()) == endString and i > first) {
            last = initial_index+i+1;
            break;
        }
    }
    return last;
}

void AnalyticsMainWindow::get_properties()
{
    QString classid = "";
    if(ui->lc_checkBox_person->isChecked()) {
        if (classid.isEmpty())
            classid = "0" ;
        else classid = classid + ";0";
    }
    if(ui->lc_checkBox_face->isChecked()) {
        if (classid.isEmpty())
            classid = "2" ;
        else classid = classid + ";2";
    }
    if(ui->lc_checkBox_bag->isChecked()) {
        if (classid.isEmpty())
            classid = "1" ;
        else classid = classid + ";1";
    }
    linecrossing.classid = classid;

    switch(ui->modeSlider->value())
    {
    case 0  :
        linecrossing.mode = "loose";
        break;
    case 1  :
        linecrossing.mode = "balanced";
        break;
    case 2  :
        linecrossing.mode = "strict";
        break;
    }

    switch(ui->lc_enabled->isChecked())
    {
    case 0  :
        linecrossing.enable = "0";
        break; //optional
    case 1  :
        linecrossing.enable = "1";
        break; //optional
    }

    switch(ui->lc_extend->isChecked())
    {
    case 0  :
        linecrossing.extend = "0";
        break; //optional
    case 1  :
        linecrossing.extend = "1";
        break; //optional
    }


    linecrossing.lc_coor_entry = ui->lineEdit_3->text() + ";" + ui->lineEdit->text();
    linecrossing.lc_coor_exit = ui->lineEdit_4->text() + ";" + ui->lineEdit_2->text();
    overcrowding.roi_oc = ui->lineEdit_5->text();

    classid = "";
    if(ui->oc_checkBox_person_2->isChecked()) {
        if (classid.isEmpty())
            classid = "0" ;
        else classid = classid + ";0";
    }
    if(ui->oc_checkBox_face_2->isChecked()) {
        if (classid.isEmpty())
            classid = "1" ;
        else classid = classid + ";1";
    }
    if(ui->oc_checkBox_bag_2->isChecked()) {
        if (classid.isEmpty())
            classid = "2" ;
        else classid = classid + ";2";
    }
    overcrowding.classid = classid;

    overcrowding.threshold = QString::number(ui->spinBox->value());


    switch(ui->oc_enabled->isChecked())
    {
    case 0  :
        overcrowding.enable = "0";
        break; //optional
    case 1  :
        overcrowding.enable = "1";
        break; //optional
    }

    switch(ui->dr_enabled->isChecked())
    {
    case 0  :
        direction.enable = "0";
        break; //optional
    case 1  :
        direction.enable = "1";
        break; //optional
    }

    classid = "";
    if(ui->dr_checkBox_person_2->isChecked()) {
        if (classid.isEmpty())
            classid = "0" ;
        else classid = classid + ";0";
    }
    if(ui->dr_checkBox_face_2->isChecked()) {
        if (classid.isEmpty())
            classid = "1" ;
        else classid = classid + ";1";
    }
    if(ui->dr_checkBox_bag_2->isChecked()) {
        if (classid.isEmpty())
            classid = "2" ;
        else classid = classid + ";2";
    }
    direction.classid = classid;

    if(!ui->east_linedit->text().isEmpty())
    {
        struct DirectionCoor direction_coor;
        direction_coor.dir = "East";
        direction_coor.coor = ui->east_linedit->text();
        direction.data.append(direction_coor);
    }

    if(!ui->west_linedit->text().isEmpty())
    {
        struct DirectionCoor direction_coor;
        direction_coor.dir = "West";
        direction_coor.coor = ui->west_linedit->text();
        direction.data.append(direction_coor);
    }
    if(!ui->north_linedit->text().isEmpty())
    {
        struct DirectionCoor direction_coor;
        direction_coor.dir = "North";
        direction_coor.coor = ui->north_linedit->text();
        direction.data.append(direction_coor);
    }
    if(!ui->south_linedit->text().isEmpty())
    {
        struct DirectionCoor direction_coor;
        direction_coor.dir = "South";
        direction_coor.coor = ui->south_linedit->text();
        direction.data.append(direction_coor);
    }
    qDebug()<< "direction.data.length():: " << direction.data.length();
}

void AnalyticsMainWindow::replace_data(QString substring, QString pattern, QString subproperty, int parentfirst)
{
    int first = substring.indexOf(subproperty) + subproperty.length();
    int last = end_indexof(substring, first, "\n", parentfirst);

    substring = cfg_data.mid(first + parentfirst, last- first - parentfirst);

    cfg_data.replace(first + parentfirst,
                     last- first - parentfirst, QString(pattern + "\n"));

    qDebug()<<"caught at: "<<substring;
}

void AnalyticsMainWindow::save_nvdsanalytics_cfg(QString data)
{
    qDebug()<<"save_nvdsanalytics_cfg call ";

    //    QString qPath("./resources/cfg/mod_config_nvdsanalytics_htpa.txt");
    QString qPath("/home/sigmind/analytics_tool_sabbir/resources/cfg/config_nvdsanalytics_htpa.txt");

    QFile qFile(qPath);
    if (qFile.open(QIODevice::WriteOnly)) {
        QTextStream out(&qFile); out << data;
        qFile.close();
    }
}

void AnalyticsMainWindow::on_pushButton_clicked()
{
    if(ui->label_14->isVisible())
    {
        QMessageBox msgBox;
        msgBox.setText("Please fill up the required fields!");
        msgBox.exec();
        return;
    }
    get_properties();

    cfg_data = read_nvdsanalytics_cfg();

    QString streamId = QString::number(ui->comboBox->currentIndex());


    if(cfg_data.contains("\n[line-crossing-stream-"+streamId+"]\n"))
    {
//        qDebug()<<"on_pushButton_clicked for change cfg";

        switch(linecrossing.enable.mid(0,1).toInt())
        {
        case 0  :
            //                              Replace with,                     property,                        subproperty,
            edit_nvdsanalytics_cfg(     linecrossing.enable,    "\n[line-crossing-stream-"+streamId+"]\n",    "\nenable=");
            break;

        case 1  :
            qDebug()<<" TEST 14: "<<cfg_data.contains("\n[line-crossing-stream-"+streamId+"]\n");
            //                              Replace with,                     property,                        subproperty,
            edit_nvdsanalytics_cfg(    linecrossing.enable,    "\n[line-crossing-stream-"+streamId+"]\n",    "\nenable=");
            //edit_nvdsanalytics_cfg(    linecrossing.classid,    "\n[line-crossing-stream-"+streamId+"]\n",    "\nclass-id=");
            edit_nvdsanalytics_cfg(    linecrossing.mode,       "\n[line-crossing-stream-"+streamId+"]\n",    "\nmode=");
            edit_nvdsanalytics_cfg(    linecrossing.extend,       "\n[line-crossing-stream-"+streamId+"]\n",    "\nextend=");
            edit_nvdsanalytics_cfg(    linecrossing.lc_coor_entry,    "\n[line-crossing-stream-"+streamId+"]\n",   "\nline-crossing-Entry=");
            edit_nvdsanalytics_cfg(    linecrossing.lc_coor_exit,    "\n[line-crossing-stream-"+streamId+"]\n",   "\nline-crossing-Exit=");
            break;
        }

        QMessageBox msgBox;
        msgBox.setText("Changes Saved!");
        msgBox.setInformativeText("Please restart WatchCam for the applied changes to take effect.");
        msgBox.exec();
        save_nvdsanalytics_cfg(cfg_data);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("No such properties for the current stream.");
        msgBox.setInformativeText("Do you want to create them automatically?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        msgBox.setStyleSheet("QMessageBox {height: 50; width = 150}");
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Yes:{
            // Save was clicked
            cfg_data.append("\n[line-crossing-stream-"+streamId+"]\n");
            cfg_data.append("enable=1\n");
            cfg_data.append("line-crossing-Exit=1388;595;1382;829;386;857;1605;876\n");
            cfg_data.append("line-crossing-Entry=1388;595;1382;829;386;857;1605;876\n");
            cfg_data.append("class-id=2\n");
            cfg_data.append("mode=balanced\n");
            cfg_data.append("extend=1\n");

            switch(linecrossing.enable.mid(0,1).toInt())
            {
            case 0  :
                //                              Replace with,                     property,                        subproperty,
                edit_nvdsanalytics_cfg(     linecrossing.enable,    "\n[line-crossing-stream-"+streamId+"]\n",    "\nenable=");
                break;

            case 1  :
                qDebug()<<" TEST 14: "<<cfg_data.contains("\n[line-crossing-stream-"+streamId+"]\n");
                //                              Replace with,                     property,                        subproperty,
                edit_nvdsanalytics_cfg(    linecrossing.enable,    "\n[line-crossing-stream-"+streamId+"]\n",    "\nenable=");
                edit_nvdsanalytics_cfg(    linecrossing.classid,    "\n[line-crossing-stream-"+streamId+"]\n",    "\nclass-id=");
                edit_nvdsanalytics_cfg(    linecrossing.mode,       "\n[line-crossing-stream-"+streamId+"]\n",    "\nmode=");
                edit_nvdsanalytics_cfg(    linecrossing.extend,       "\n[line-crossing-stream-"+streamId+"]\n",    "\nextend=");
                edit_nvdsanalytics_cfg(    linecrossing.lc_coor_entry,    "\n[line-crossing-stream-"+streamId+"]\n",   "\nline-crossing-Entry=");
                edit_nvdsanalytics_cfg(    linecrossing.lc_coor_exit,    "\n[line-crossing-stream-"+streamId+"]\n",   "\nline-crossing-Exit=");
                break;
            }

            QMessageBox msgBox;
            msgBox.setText("Changes Saved!");
            msgBox.setInformativeText("Please restart WatchCam for the applied changes to take effect.");
            msgBox.exec();

            save_nvdsanalytics_cfg(cfg_data);
            break;}
        case QMessageBox::No:
            // Don't Save was clicked
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            break;
        }


    }

}


void AnalyticsMainWindow::on_comboBox_currentIndexChanged(int index)
{
    //    if(rtspURLs.size()!= 0) ui->lineEdit_rtsp->setText(rtspURLs[index]);
    ui->lineEdit_rtsp->setText(rtspURLs[index]);
}



void AnalyticsMainWindow::on_lc_enabled_toggled(bool checked)
{
    if(checked)
    {
        graphicsView->flags.mode = 0;
        ui->groupBox->setEnabled(true);
        ui->groupBox_2->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->groupBox_7->setEnabled(true);
    }

    else
    {
        ui->groupBox->setEnabled(false);
        ui->groupBox_2->setEnabled(false);
        ui->groupBox_5->setEnabled(false);
        ui->groupBox_7->setEnabled(false);
    }
}

void AnalyticsMainWindow::on_lc_mode_entry_cb_toggled(bool checked)
{
    if(checked)
    {
        graphicsView->flags.mode = 0;
        ui->lc_mode_exit_cb->setChecked(false);
        ui->lc_mode_entry_cb->setDisabled(true);
    }
    else
    {
        ui->lc_mode_entry_cb->setEnabled(true);
    }
}

void AnalyticsMainWindow::on_lc_mode_exit_cb_toggled(bool checked)
{
    if(checked)
    {
        graphicsView->flags.mode = 0;
        ui->lc_mode_entry_cb->setChecked(false);
        ui->lc_mode_exit_cb->setDisabled(true);
    }
    else
    {
        ui->lc_mode_exit_cb->setEnabled(true);
    }
}


void AnalyticsMainWindow::on_pushButton_2_clicked()
{
    if(ui->label_15->isVisible())
    {
        QMessageBox msgBox;
        msgBox.setText("Please fill up the required fields!");
        msgBox.exec();
        return;
    }

    get_properties();

    cfg_data = read_nvdsanalytics_cfg();

    QString streamId = QString::number(ui->comboBox->currentIndex());

    if(cfg_data.contains("\n[overcrowding-stream-"+streamId+"]\n"))
    {

        switch(overcrowding.enable.mid(0,1).toInt())
        {
        case 0  :
            //                             Replace with,                     property,                        subproperty,
            edit_nvdsanalytics_cfg(     overcrowding.enable,    "\n[overcrowding-stream-"+streamId+"]\n",    "\nenable=");
            break;

        case 1  :
            //                             Replace with,                     property,                        subproperty,
            edit_nvdsanalytics_cfg(     overcrowding.enable,      "\n[overcrowding-stream-"+streamId+"]\n",    "\nenable=");
            edit_nvdsanalytics_cfg(     overcrowding.classid,     "\n[overcrowding-stream-"+streamId+"]\n",    "\nclass-id=");
            edit_nvdsanalytics_cfg(     overcrowding.threshold,   "\n[overcrowding-stream-"+streamId+"]\n",    "\nobject-threshold=");
            edit_nvdsanalytics_cfg(     overcrowding.roi_oc,      "\n[overcrowding-stream-"+streamId+"]\n",    "\nroi-OC=");
        }
        save_nvdsanalytics_cfg(cfg_data);

        QMessageBox msgBox;
        msgBox.setText("Changes Saved!");
        msgBox.setInformativeText("Please restart WatchCam for the applied changes to take effect.");
        msgBox.exec();

    }

    else
    {
        QMessageBox msgBox;
        msgBox.setText("No such properties for the current stream.");
        msgBox.setInformativeText("Do you want to create them automatically?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Yes:
        {// Save was clicked
            cfg_data.append("\n[overcrowding-stream-"+streamId+"]\n");
            cfg_data.append("enable=1\n");
            cfg_data.append("class-id=2\n");
            cfg_data.append("object-threshold=0\n");
            cfg_data.append("roi-OC=1\n");

            switch(overcrowding.enable.mid(0,1).toInt())
            {
            case 0  :
                //                             Replace with,                     property,                        subproperty,
                edit_nvdsanalytics_cfg(     overcrowding.enable,    "\n[overcrowding-stream-"+streamId+"]\n",    "\nenable=");
                break;

            case 1  :
                //                             Replace with,                     property,                        subproperty,
                edit_nvdsanalytics_cfg(     overcrowding.enable,      "\n[overcrowding-stream-"+streamId+"]\n",    "\nenable=");
                edit_nvdsanalytics_cfg(     overcrowding.classid,     "\n[overcrowding-stream-"+streamId+"]\n",    "\nclass-id=");
                edit_nvdsanalytics_cfg(     overcrowding.threshold,   "\n[overcrowding-stream-"+streamId+"]\n",    "\nobject-threshold=");
                edit_nvdsanalytics_cfg(     overcrowding.roi_oc,      "\n[overcrowding-stream-"+streamId+"]\n",    "\nroi-OC=");
            }

            save_nvdsanalytics_cfg(cfg_data);
            QMessageBox msgBox;
            msgBox.setText("Changes Saved!");
            msgBox.setInformativeText("Please restart WatchCam for the applied changes to take effect.");
            msgBox.exec();


            break;}

        case QMessageBox::No:
            // Don't Save was clicked
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            break;
        }
    }
}

void AnalyticsMainWindow::on_oc_enabled_toggled(bool checked)
{
    if(checked)
    {
        ui->groupBox_10->setEnabled(true);
        ui->groupBox_11->setEnabled(true);
    }

    else
    {
        ui->groupBox_10->setEnabled(false);
        ui->groupBox_11->setEnabled(false);
    }
}

void AnalyticsMainWindow::on_DrawRect_clicked()
{
    graphicsView->flags.mode = 1;
    ui->DrawLine->setChecked(false);
}

void AnalyticsMainWindow::on_DrawLine_clicked()
{
    if(ui->DrawLine->isChecked())
    {
        if(ui->lc_mode_entry_cb->isChecked())
        {graphicsView->flags.mode = 0;
            ui->lc_mode_entry_cb->setDisabled(true);
            ui->lc_mode_exit_cb->setEnabled(true);}

        else if(ui->lc_mode_exit_cb->isChecked())
        {
            graphicsView->flags.mode = 0;
            ui->lc_mode_exit_cb->setDisabled(true);
            ui->lc_mode_entry_cb->setEnabled(true);}

        else
        {
            ui->lc_mode_exit_cb->setEnabled(true);
            ui->lc_mode_entry_cb->setEnabled(true);
        }
    }

    ui->DrawRect->setChecked(false);
}

void AnalyticsMainWindow::on_ClearDrawing_clicked()
{
    graphicsView->flags.end_position_flag=0;
    graphicsView->flags.initial_position_flag=0;
    graphicsView->flags.nearest_point = 0;
    graphicsView->flags.resize = 0;
    update();
}


void AnalyticsMainWindow::on_SetDrawing_clicked()
{
//    int mode;
//    if(ui->lc_mode_entry_cb->isChecked())
//    {
//        mode = 0;
//    }
//    else    mode = 1;


    qDebug()<<"going in save(): "<<graphicsView->flags.mode;
    graphicsView->save(graphicsView->flags.mode);
    qDebug()<<"coming out save() : "<<graphicsView->flags.mode;


    switch(ui->tabWidget->currentIndex())
    {
    case 0:
    {
        if(ui->lc_mode_entry_cb->isChecked())
        {



            if(graphicsView->flags.mode == 0)
            {
                MyGraphicsView::LineCrossings obj = graphicsView->point.saved_line_points[graphicsView->point.saved_line_points.length()-1];
                QPair <QPoint, QPoint> points = obj.line;

                QString lc_Coor = "";
                lc_Coor.append(QString::number(points.first.x()));
                lc_Coor.append(";" + QString::number(points.first.y()));
                lc_Coor.append(";" + QString::number(points.second.x()));
                lc_Coor.append(";" + QString::number(points.second.y()));
                qDebug()<<"lc_coor "<< lc_Coor;
                ui->lineEdit->setText(lc_Coor);
                ui->lineEdit_3->clear();
            }

            if(graphicsView->flags.mode == 2)
            {
                MyGraphicsView::LineCrossings obj = graphicsView->point.saved_line_points[graphicsView->point.saved_line_points.length()-1];
                QPair <QPoint, QPoint> points = obj.direction;
                QString lc_dir = "";
                lc_dir.append(QString::number(points.first.x()));
                lc_dir.append(";" + QString::number(points.first.y()));
                lc_dir.append(";" + QString::number(points.second.x()));
                lc_dir.append(";" + QString::number(points.second.y()));
                ui->lineEdit_3->setText(lc_dir);
            }

        }

        else
        {
            if(graphicsView->flags.mode == 0)
            {
                MyGraphicsView::LineCrossings obj = graphicsView->point.saved_line_points[graphicsView->point.saved_line_points.length()-1];
                QPair <QPoint, QPoint> points = obj.line;

                QString lc_Coor = "";
                lc_Coor.append(QString::number(points.first.x()));
                lc_Coor.append(";" + QString::number(points.first.y()));
                lc_Coor.append(";" + QString::number(points.second.x()));
                lc_Coor.append(";" + QString::number(points.second.y()));
                ui->lineEdit_2->setText(lc_Coor);
                ui->lineEdit_4->clear();
            }


            if(graphicsView->flags.mode == 2)
            {
                MyGraphicsView::LineCrossings obj = graphicsView->point.saved_line_points[graphicsView->point.saved_line_points.length()-1];
                QPair <QPoint, QPoint> points = obj.direction;
                QString lc_dir = "";
                lc_dir.append(QString::number(points.first.x()));
                lc_dir.append(";" + QString::number(points.first.y()));
                lc_dir.append(";" + QString::number(points.second.x()));
                lc_dir.append(";" + QString::number(points.second.y()));
                ui->lineEdit_4->setText(lc_dir);
            }
        }

        break;
    }

    case 1:
    {
        overcrowding.roi_oc = "";
        QPair <QPoint, QPoint> points  = graphicsView->point.saved_rect_points[graphicsView->point.saved_rect_points.length()-1];

        overcrowding.roi_oc.append(QString::number(points.first.x()));
        overcrowding.roi_oc.append(";" + QString::number(points.first.y()));
        overcrowding.roi_oc.append(";" + QString::number(points.second.x()));
        overcrowding.roi_oc.append(";" + QString::number(points.first.y()));
        overcrowding.roi_oc.append(";" + QString::number(points.second.x()));
        overcrowding.roi_oc.append(";" + QString::number(points.second.y()));
        overcrowding.roi_oc.append(";" + QString::number(points.first.x()));
        overcrowding.roi_oc.append(";" + QString::number(points.second.y()));

        ui->lineEdit_5->setText(overcrowding.roi_oc);


        //        cfg_data = read_nvdsanalytics_cfg();
        //        QString streamId = QString::number(ui->comboBox->currentIndex());
        //        edit_nvdsanalytics_cfg(  overcrowding.roi_oc,    "\n[overcrowding-stream-"+streamId+"]\n",   "\nroi-OC");
        //        save_nvdsanalytics_cfg(cfg_data);
        break;
    }

    case 2:
    {
        QPair <QPoint, QPoint> points = graphicsView->point.saved_direction_points[graphicsView->point.saved_direction_points.length()-1];
        QString direction = "";
        direction.append(QString::number(points.first.x()));
        direction.append(";" + QString::number(points.first.y()));
        direction.append(";" + QString::number(points.second.x()));
        direction.append(";" + QString::number(points.second.y()));

        if(ui->checkbox_east->isChecked())
        {
            ui->east_linedit->setText(direction);
        }

        if(ui->checkbox_west->isChecked())
        {
            ui->west_linedit->setText(direction);
        }

        if(ui->checkbox_north->isChecked())
        {
            ui->north_linedit->setText(direction);
        }

        if(ui->checkbox_south->isChecked())
        {
            ui->south_linedit->setText(direction);
        }


        graphicsView->flags.initial_position_flag = 0;
        graphicsView->flags.end_position_flag = 0;
        graphicsView->flags.resize = 0;
        graphicsView->flags.nearest_point = 0;

        return;
    }

    }
    if(graphicsView->flags.mode == 2){goto oidike;}

    if(graphicsView->flags.mode == 0)
    {
        graphicsView->flags.mode = 2;
    }

oidike:  if(graphicsView->flags.mode == 2){graphicsView->flags.mode == 0;}
    graphicsView->flags.initial_position_flag = 0;
    graphicsView->flags.end_position_flag = 0;
    graphicsView->flags.resize = 0;
    graphicsView->flags.nearest_point = 0;

}

void AnalyticsMainWindow::on_tabWidget_currentChanged(int index)
{
    switch(index) {
    case 0:
        ui->DrawLine->setEnabled(true);
        ui->DrawRect->setChecked(false);
        ui->DrawRect->setEnabled(false);

        ui->lc_mode_entry_cb->setDisabled(true);
        ui->lc_mode_exit_cb->setDisabled(true);


        graphicsView->flags.end_position_flag=0;
        graphicsView->flags.initial_position_flag=0;
        graphicsView->flags.nearest_point = 0;
        graphicsView->flags.resize = 0;
        graphicsView->flags.mode = -1;
        update();

        break;
    case 1:
        // code block
        ui->DrawLine->setEnabled(false);
        ui->DrawLine->setChecked(false);
        ui->DrawRect->setEnabled(true);


        graphicsView->flags.end_position_flag=0;
        graphicsView->flags.initial_position_flag=0;
        graphicsView->flags.nearest_point = 0;
        graphicsView->flags.resize = 0;
        graphicsView->flags.mode = -1;
        update();

        break;

    case 3:


        graphicsView->flags.end_position_flag=0;
        graphicsView->flags.initial_position_flag=0;
        graphicsView->flags.nearest_point = 0;
        graphicsView->flags.resize = 0;
        graphicsView->flags.mode = -1;
        update();

        break;

    }
}

bool AnalyticsMainWindow::checkClassValidity(int property)
{
    switch(property)
    {
    case 0:
    {
        if((ui->lc_checkBox_person->isChecked() || ui->lc_checkBox_face->isChecked() || ui->lc_checkBox_bag->isChecked()))
        {
            return true;
        }
        else return false;
    }

    case 1:
    {
        if((ui->oc_checkBox_person_2->isChecked() || ui->oc_checkBox_face_2->isChecked() || ui->oc_checkBox_bag_2->isChecked()))
        {
            qDebug()<<"retuirn true";
            return true;
        }
        else return false;
    }

    }

}

void AnalyticsMainWindow::on_lc_checkBox_person_toggled(bool checked)
{
    if(checkClassValidity(0)) ui->label_14->hide();
    else ui->label_14->show();

}

void AnalyticsMainWindow::on_lc_checkBox_face_toggled(bool checked)
{
    if(checkClassValidity(0)) ui->label_14->hide();
    else ui->label_14->show();
}

void AnalyticsMainWindow::on_lc_checkBox_bag_toggled(bool checked)
{
    if(checkClassValidity(0)) ui->label_14->hide();
    else ui->label_14->show();
}

//bool AnalyticsMainWindow::onWarned()
//{
//    ui->pushButton->setDisabled(true);
//}


void AnalyticsMainWindow::on_oc_checkBox_person_2_toggled(bool checked)
{
    if(checkClassValidity(1)) ui->label_15->hide();
    else ui->label_15->show();
}

void AnalyticsMainWindow::on_oc_checkBox_face_2_toggled(bool checked)
{
    if(checkClassValidity(1)) ui->label_15->hide();
    else ui->label_15->show();
}

void AnalyticsMainWindow::on_oc_checkBox_bag_2_toggled(bool checked)
{
    if(checkClassValidity(1)) ui->label_15->hide();
    else ui->label_15->show();
}

void AnalyticsMainWindow::on_pushButton_3_clicked()
{
//    if(ui->label_15->isVisible())
//    {
//        QMessageBox msgBox;
//        msgBox.setText("Please fill up the required fields!");
//        msgBox.exec();
//        return;
//    }

    get_properties();

    cfg_data = read_nvdsanalytics_cfg();

    QString streamId = QString::number(ui->comboBox->currentIndex());

    if(cfg_data.contains("\n[direction-detection-stream-"+streamId+"]\n"))
    {

        switch(direction.enable.mid(0,1).toInt())
        {
        case 0  :
            //                             Replace with,                     property,                 subproperty,
            edit_nvdsanalytics_cfg(     direction.enable,    "\n[direction-detection-stream-"+streamId+"]\n",    "enable=");
            break;

        case 1  :
            //                             Replace with,                     property,                        subproperty,
            edit_nvdsanalytics_cfg(     direction.enable,      "\n[direction-detection-stream-"+streamId+"]\n",       "enable=");
            edit_nvdsanalytics_cfg(     direction.classid,     "\n[direction-detection-stream-"+streamId+"]\n",       "\nclass-id=");

            for (int i = 0; i < direction.data.length(); i++)
            {
                qDebug()<< "direction.data[i].coor " << direction.data[i].coor
                        << "direction.data[i].dir  " << direction.data[i].dir;
                edit_nvdsanalytics_cfg(     direction.data[i].coor,   "\n[direction-detection-stream-"+streamId+"]\n",    "direction-"+ direction.data[i].dir +"=");
            }
        }
        save_nvdsanalytics_cfg(cfg_data);

        QMessageBox msgBox;
        msgBox.setText("Changes Saved!");
        msgBox.setInformativeText("Please restart WatchCam for the applied changes to take effect.");
        msgBox.exec();

    }

    else
    {
        QMessageBox msgBox;
        msgBox.setText("No such properties for the current stream.");
        msgBox.setInformativeText("Do you want to create them automatically?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Yes:
        {// Save was clicked
            cfg_data.append("\n[direction-detection-stream-"+streamId+"]\n");
            cfg_data.append("enable=1\n");
            //cfg_data.append("class-id=2\n");

            for (int i = 0; i < direction.data.length(); i++)
            {
                cfg_data.append("direction-"+ direction.data[i].dir +"=284;840;360;662\n");
            }

            switch(direction.enable.mid(0,1).toInt())
            {
            case 0  :
                //                             Replace with,                     property,                 subproperty,
                edit_nvdsanalytics_cfg(     direction.enable,    "\n[direction-detection-stream-"+streamId+"]\n",    "enable=");
                break;

            case 1  :
                //                             Replace with,                     property,                        subproperty,
                edit_nvdsanalytics_cfg(     direction.enable,      "\n[direction-detection-stream-"+streamId+"]\n",       "enable=");
                edit_nvdsanalytics_cfg(     direction.classid,     "\n[direction-detection-stream-"+streamId+"]\n",       "\nclass-id=");

                for (int i = 0; i < direction.data.length(); i++)
                {
                    edit_nvdsanalytics_cfg(     direction.data[i].coor,   "\n[direction-detection-stream-"+streamId+"]\n",    "direction-"+ direction.data[i].dir +"=");
                }
            }

            save_nvdsanalytics_cfg(cfg_data);
            QMessageBox msgBox;
            msgBox.setText("Changes Saved!");
            msgBox.setInformativeText("Please restart WatchCam for the applied changes to take effect.");
            msgBox.exec();


            break;}

        case QMessageBox::No:
            // Don't Save was clicked
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            break;
        }
    }

    graphicsView->point.saved_direction_points.clear();
    graphicsView->flags.end_position_flag=0;
    graphicsView->flags.initial_position_flag=0;
    graphicsView->flags.nearest_point = 0;
    graphicsView->flags.resize = 0;
    graphicsView->update();
}

void AnalyticsMainWindow::on_checkbox_east_toggled(bool checked)
{
    if(checked)
    {
        graphicsView->flags.mode = 3;

        ui->checkbox_west->setChecked(false);
        ui->checkbox_north->setChecked(false);
        ui->checkbox_south->setChecked(false);
    }
}

void AnalyticsMainWindow::on_checkbox_west_toggled(bool checked)
{
    if(checked)
    {
        graphicsView->flags.mode = 3;

        ui->checkbox_east->setChecked(false);
        ui->checkbox_north->setChecked(false);
        ui->checkbox_south->setChecked(false);
    }
}

void AnalyticsMainWindow::on_checkbox_north_toggled(bool checked)
{
    if(checked)
    {
        graphicsView->flags.mode = 3;

        ui->checkbox_east->setChecked(false);
        ui->checkbox_west->setChecked(false);
        ui->checkbox_south->setChecked(false);
    }
}

void AnalyticsMainWindow::on_checkbox_south_toggled(bool checked)
{
    if(checked)
    {
        graphicsView->flags.mode = 3;

        ui->checkbox_east->setChecked(false);
        ui->checkbox_west->setChecked(false);
        ui->checkbox_north->setChecked(false);
    }
}
