# This Python file uses the following encoding: utf-8

from os import getcwd

from PySide6.QtWidgets import QApplication, QFileDialog


if __name__ == "__main__":
    app = QApplication([])
#    dialog = QFileDialog()
    dirName = QFileDialog.getExistingDirectory(None,"Labryinths",
                getcwd(), QFileDialog.Option.ShowDirsOnly)
    if (dirName !=  ""):
        print(dirName)
    else:
        print(getcwd())
    