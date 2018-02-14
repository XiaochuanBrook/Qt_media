#include <QtGui>

#include "editor.h"
#include "txtmainwindow.h"

Txtmaiwindow::Txtmaiwindow()
{
    workspace = new QWorkspace;
    setCentralWidget(workspace);
    connect(workspace, SIGNAL(windowActivated(QWidget *)),
            this, SLOT(updateMenus()));

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    setWindowTitle(tr("MDI Editor"));
    setWindowIcon(QPixmap(":/images/icon.png"));
}

void Txtmaiwindow::newFile()
{
    Editor *editor = createEditor();
    editor->newFile();
    editor->show();
}

void Txtmaiwindow::openFile(const QString &fileName)
{
    Editor *editor = createEditor();
    if (editor->openFile(fileName)) {
        editor->show();
    } else {
        editor->close();
    }
}

void Txtmaiwindow::closeEvent(QCloseEvent *event)
{
    workspace->closeAllWindows();
    if (activeEditor()) {
        event->ignore();
    } else {
        event->accept();
    }
}

void Txtmaiwindow::open()
{
    Editor *editor = createEditor();
    if (editor->open()) {
        editor->show();
    } else {
        editor->close();
    }
}

void Txtmaiwindow::save()
{
    if (activeEditor())
        activeEditor()->save();
}

void Txtmaiwindow::saveAs()
{
    if (activeEditor())
        activeEditor()->saveAs();
}

void Txtmaiwindow::cut()
{
    if (activeEditor())
        activeEditor()->cut();
}

void Txtmaiwindow::copy()
{
    if (activeEditor())
        activeEditor()->copy();
}

void Txtmaiwindow::paste()
{
    if (activeEditor())
        activeEditor()->paste();
}

void Txtmaiwindow::about()
{
    QMessageBox::about(this, tr("About MDI Editor"),
            tr("<h2>Editor 1.1</h2>"
               "<p>Copyright &copy; 2006 Software Inc."
               "<p>MDI Editor is a small application that demonstrates "
               "QWorkspace."));
}

void Txtmaiwindow::updateMenus()
{
    bool hasEditor = (activeEditor() != 0);
    bool hasSelection = activeEditor()
                        && activeEditor()->textCursor().hasSelection();

    saveAction->setEnabled(hasEditor);
    saveAsAction->setEnabled(hasEditor);
    pasteAction->setEnabled(hasEditor);
    cutAction->setEnabled(hasSelection);
    copyAction->setEnabled(hasSelection);
    closeAction->setEnabled(hasEditor);
    closeAllAction->setEnabled(hasEditor);
    tileAction->setEnabled(hasEditor);
    cascadeAction->setEnabled(hasEditor);
    nextAction->setEnabled(hasEditor);
    previousAction->setEnabled(hasEditor);
    separatorAction->setVisible(hasEditor);

    if (activeEditor())
        activeEditor()->windowMenuAction()->setChecked(true);
}

void Txtmaiwindow::createActions()
{
    newAction = new QAction(QIcon(":/images/new.png"), tr("&New"),
                            this);
    newAction->setShortcut(Qt::Key_1);
    newAction->setStatusTip(tr("Create a new file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(QIcon(":/images/open.png"), tr("&Open..."),
                             this);
    openAction->setShortcut(Qt::Key_2);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(QIcon(":/images/save.png"), tr("&Save"),
                             this);
    saveAction->setShortcut(Qt::Key_3);
    saveAction->setStatusTip(tr("Save the file to disk"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAction = new QAction(tr("Save &As..."), this);
    saveAsAction->setStatusTip(tr("Save the file under a new name"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(Qt::Key_4);
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    cutAction = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"),
                            this);
    cutAction->setShortcut(Qt::Key_5);
    cutAction->setStatusTip(tr("Cut the current selection to the "
                               "clipboard"));
    connect(cutAction, SIGNAL(triggered()), this, SLOT(cut()));

    copyAction = new QAction(QIcon(":/images/copy.png"), tr("&Copy"),
                             this);
    copyAction->setShortcut(Qt::Key_6);
    copyAction->setStatusTip(tr("Copy the current selection to the "
                                "clipboard"));
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAction = new QAction(QIcon(":/images/paste.png"), tr("&Paste"),
                              this);
    pasteAction->setShortcut(Qt::Key_7);
    pasteAction->setStatusTip(tr("Paste the clipboard's contents at "
                                 "the cursor position"));
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));

    closeAction = new QAction(tr("Cl&ose"), this);
    closeAction->setShortcut(Qt::Key_8);
    closeAction->setStatusTip(tr("Close the active window"));
    connect(closeAction, SIGNAL(triggered()),
            workspace, SLOT(closeActiveWindow()));

    closeAllAction = new QAction(tr("Close &All"), this);
    closeAllAction->setStatusTip(tr("Close all the windows"));
    connect(closeAllAction, SIGNAL(triggered()),
            workspace, SLOT(closeAllWindows()));

    tileAction = new QAction(tr("&Tile"), this);
    tileAction->setStatusTip(tr("Tile the windows"));
    connect(tileAction, SIGNAL(triggered()), workspace, SLOT(tile()));

    cascadeAction = new QAction(tr("&Cascade"), this);
    cascadeAction->setStatusTip(tr("Cascade the windows"));
    connect(cascadeAction, SIGNAL(triggered()),
            workspace, SLOT(cascade()));

    nextAction = new QAction(tr("Ne&xt"), this);
    nextAction->setShortcut(tr("Ctrl+F6"));
    nextAction->setStatusTip(tr("Move the focus to the next window"));
    connect(nextAction, SIGNAL(triggered()),
            workspace, SLOT(activateNextWindow()));

    previousAction = new QAction(tr("Pre&vious"), this);
    previousAction->setShortcut(tr("Ctrl+Shift+F6"));
    previousAction->setStatusTip(tr("Move the focus to the previous "
                                    "window"));
    connect(previousAction, SIGNAL(triggered()),
            workspace, SLOT(activatePreviousWindow()));

    separatorAction = new QAction(this);
    separatorAction->setSeparator(true);

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    windowActionGroup = new QActionGroup(this);
}

void Txtmaiwindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);

    windowMenu = menuBar()->addMenu(tr("&Window"));
    windowMenu->addAction(closeAction);
    windowMenu->addAction(closeAllAction);
    windowMenu->addSeparator();
    windowMenu->addAction(tileAction);
    windowMenu->addAction(cascadeAction);
    windowMenu->addSeparator();
    windowMenu->addAction(nextAction);
    windowMenu->addAction(previousAction);
    windowMenu->addAction(separatorAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void Txtmaiwindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
}

void Txtmaiwindow::createStatusBar()
{
    readyLabel = new QLabel(tr(" Ready"));
    statusBar()->addWidget(readyLabel, 1);
}

Editor *Txtmaiwindow::createEditor()
{
    Editor *editor = new Editor;
    connect(editor, SIGNAL(copyAvailable(bool)),
            cutAction, SLOT(setEnabled(bool)));
    connect(editor, SIGNAL(copyAvailable(bool)),
            copyAction, SLOT(setEnabled(bool)));

    workspace->addWindow(editor);
    windowMenu->addAction(editor->windowMenuAction());
    windowActionGroup->addAction(editor->windowMenuAction());

    return editor;
}

Editor *Txtmaiwindow::activeEditor()
{
    return qobject_cast<Editor *>(workspace->activeWindow());
}
void Txtmaiwindow::keyPressEvent(QKeyEvent *event)
{if(event->key()==Qt::Key_Period)
    this->close();
}
