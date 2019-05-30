#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QMediaPlaylist>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
   // void stateChanged(QMediaPlayer::State state);
    //void positionChanged(qint64 position);
    ~MainWindow();

private slots:
    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_stopButton_clicked();

    void on_timeProgress_sliderMoved(int position);

    void on_volume_sliderMoved(int position);

    void on_actionOpenFile_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QMediaPlaylist * playList;
};

#endif // MAINWINDOW_H
