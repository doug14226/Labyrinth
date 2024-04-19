# This Python file uses the following encoding: utf-8
import sys
import os


from PySide6.QtWidgets import QApplication, QWidget, QSpinBox, QPushButton
from PySide6.QtCore import QFile, QCoreApplication, Qt
from PySide6.QtUiTools import QUiLoader


class MazeSize(QWidget):
    def __init__(self):
        super(MazeSize, self).__init__()
        self.load_ui()

    def load_ui(self):
        loader = QUiLoader();
        path = os.path.join(os.path.dirname(__file__), "graphSize.ui")
        ui_file = QFile(path)
        ui_file.open(QFile.ReadOnly)
        loader.load(ui_file, self)
        ui_file.close()

def write_rc():
    r = SpinBoxR.value()
    c = SpinBoxC.value()
    output = str(r) + "\n" + str(c) +"\n"
    print(output)
    sys.exit()

def new_value():
    r = SpinBoxR.value()
    if (r%2 == 0):
        SpinBoxR.setValue(r+1)
    return

if __name__ == "__main__":
    QCoreApplication.setAttribute(Qt.AA_ShareOpenGLContexts)
    app = QApplication(sys.argv)
    app.setStyle('Macintosh')
    widget = MazeSize()
    SpinBoxR = widget.findChild(QSpinBox,"spinBox_Rows")
    SpinBoxC = widget.findChild(QSpinBox,"spinBox_Cols")
    Build = widget.findChild(QPushButton,"Build")
    Build.clicked.connect(write_rc)
    SpinBoxR.textChanged.connect(new_value)
    widget.show()
    app.exec_()
