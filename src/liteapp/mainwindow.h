#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "../api/ieditor.h"
#include "../api/iproject.h"

class LiteApp;
class MainWindow : public QMainWindow, public IEditorEvent, public IProjectEvent
{
    Q_OBJECT
public:
    friend class LiteApp;
    MainWindow(LiteApp *app);
    virtual void fireDocumentChanged(IEditor *edit, bool b);
    virtual void fireProjectChanged(IProject *project);
protected:
    virtual void closeEvent(QCloseEvent *event);
private slots:
    void saveFile();
    void newFile();
    void openFile();
    void openProject();
    void about();
    void editTabChanged(int index);
    void editTabClose(int index);
    void aboutPlugins();
public:
    void addWorkspacePane(QWidget *w, const QString &name);
    void addOutputPage(QWidget *w, const QString &name);
    void addEditor(IEditor *ed);
private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createDockWindows();
    void createOutputWidget();

    QTabWidget *editTabWidget;
    QTabWidget *outputTabWidget;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QMenu   *fileMenu;
    QMenu   *editMenu;
    QMenu   *viewMenu;
    QMenu   *buildMenu;
    QMenu   *toolMenu;
    QMenu   *helpMenu;

    QAction *openProjectAct;
    QAction *newFileAct;
    QAction *openFileAct;
    QAction *saveFileAct;
    QAction *closeFileAct;
    QAction *undoAct;
    QAction *redoAct;

    QAction *buildProjectAct;
    QAction *runAct;
    QAction *debugAct;

    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *quitAct;
    QAction *aboutPluginsAct;

    IEditor *activeEditor;
    IProject *activeProject;
    LiteApp *liteApp;
    QMap<QWidget*,IEditor*> editors;
};

#endif // MAINWINDOW_H
