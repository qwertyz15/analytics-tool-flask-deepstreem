//#ifndef ANALYTICSMAINWINDOW_H
//#define ANALYTICSMAINWINDOW_H

//#include <QWidget>

//namespace Ui {
//class AnalyticsMainWindow;
//}

//class AnalyticsMainWindow : public QWidget
//{
//    Q_OBJECT

//public:
//    explicit AnalyticsMainWindow(QWidget *parent = 0);
//    ~AnalyticsMainWindow();

//private:
//    Ui::AnalyticsMainWindow *ui;
//};

//#endif // ANALYTICSMAINWINDOW_H



#ifndef ANALYTICSMAINWINDOW_H
#define ANALYTICSMAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
//#include "discoveryobj.h"
#include <bits/stdc++.h>
#include <string>
#include <QMediaPlayer>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QGraphicsScene>
#include "mygraphicsview.h"
#include <QGraphicsVideoItem>
#include <QSize>

namespace Ui {
class AnalyticsMainWindow;
}
class AnalyticsMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AnalyticsMainWindow(QWidget *parent = 0);
    ~AnalyticsMainWindow();
//    int getRTSPUrl(const char*mediaAddr,std::string&rtspUrl);
//    int getProfile(const char*mediaAddr,std::string&profileToken);
//    int DeviceInformation(char*szHostName,QString &pass_pass);
//    int getMediaUrl(/* const char* deviceAddr,*/std::string& MediaAddr);
//    int ptzContinuousMove(/*const char* deviceAddr,*/int command);
//    int ptzRelativeMove(/*const char* deviceAddr,*/int command);
//    int ptz();
    void loadFromTextFile();
//    void editSourceNumber();
    void TemplateforSourecFile();
    QString read_nvdsanalytics_cfg();
    void edit_nvdsanalytics_cfg(QString pattern, QString property, QString subproperty);
    int end_indexof(QString mainString, int first, QString endString, int initial_index);
    void save_nvdsanalytics_cfg(QString data);
    void get_properties();
    void replace_data(QString substring, QString pattern, QString subproperty, int parentfirst);
    QList<QString> rtspURLs;
    QString cfg_data;
    bool checkClassValidity(int);
    bool checkInputValidity();

signals:
    void warned();


private slots:
    //bool onWarned();
//    void on_btnSendProb_clicked();

//    void onDiscoveredDevice(DescDevice);

    void on_display_video_clicked();

//    void on_pushButton_add_clicked();

//    void on_pushButton_login_clicked();

//    void on_right_clicked();

//    void on_left_clicked();

//    void on_down_clicked();

//    void on_up_clicked();

//    void on_ZoomIn_clicked();

//    void on_ZoomOut_clicked();

//    void on_leftupper_clicked();

//    void on_leftlower_clicked();

//    void on_rightupper_clicked();

//    void on_rightlower_clicked();

//    void on_speed_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_lc_mode_entry_cb_toggled(bool checked);

    void on_lc_mode_exit_cb_toggled(bool checked);

    void on_lc_enabled_toggled(bool checked);

    void on_pushButton_2_clicked();

    void on_oc_enabled_toggled(bool checked);

    void on_DrawRect_clicked();

    void on_DrawLine_clicked();

    void on_ClearDrawing_clicked();

    void on_SetDrawing_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_lc_checkBox_person_toggled(bool checked);

    void on_lc_checkBox_face_toggled(bool checked);

    void on_lc_checkBox_bag_toggled(bool checked);

    void on_oc_checkBox_person_2_toggled(bool checked);

    void on_oc_checkBox_face_2_toggled(bool checked);

    void on_oc_checkBox_bag_2_toggled(bool checked);

    void on_pushButton_3_clicked();

    void on_checkbox_east_toggled(bool checked);

    void on_checkbox_west_toggled(bool checked);

    void on_checkbox_north_toggled(bool checked);

    void on_checkbox_south_toggled(bool checked);

private:
    Ui::AnalyticsMainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsVideoItem *videoItem;
    QMediaPlayer* mediaPlayer;
    QSize videoSize ;
    MyGraphicsView *graphicsView;
    QVBoxLayout *layout;
//    DiscoveryObj *discoveryObj = NULL;
    std::string port,ip_address;
    std::string m_passwd,m_username,m_deviceurl,rtsp_url,rtsp;
    QString  IP_add,addrtsp,PORT,Password,Username,RTSP,Device_INFO,Table_rtsp;

    struct Properties {
        std::string lastName;
        std::string firstName;
    };

    struct LineCrossing {
        QString property;
        QString enable;
        QString classid;
        QString mode;
        QString extend;
        QString lc_mode;
        QString lc_coor_entry;
        QString lc_coor_exit;
    } linecrossing;

    struct OverCrowding {
        QString property;
        QString enable;
        QString roi_oc;
        QString threshold;
        QString classid;
    } overcrowding;

    struct DirectionCoor{
        QString dir;
        QString coor;
    };

    struct Direction {
        QList<DirectionCoor> data;
        QString enable;
        QString classid;
    } direction;

};

#endif // ANALYTICSMAINWINDOW_H
