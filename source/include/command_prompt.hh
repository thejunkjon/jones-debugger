//
// MIT License
//
// Copyright 2019
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef JONES_DEBUGGER_COMMAND_PROMPT_HH
#define JONES_DEBUGGER_COMMAND_PROMPT_HH

#include <QCompleter>
#include <QKeyEvent>
#include <QStringListModel>
#include <QTextEdit>
#include <memory>

namespace Ui {

class CommandPrompt : public QTextEdit {
  Q_OBJECT

public:
  CommandPrompt(QWidget *parent = nullptr);
  ~CommandPrompt() override;

  void setCompleter(std::unique_ptr<QCompleter> completer);
  QCompleter *completer() const;

protected:
  void keyPressEvent(QKeyEvent *event) override;
  void focusInEvent(QFocusEvent *event) override;

private slots:
  void insertCompletion(const QString &completion);

private:
  void processAutoComplete(QKeyEvent *event);
  void processCommand(QKeyEvent *event);
  QString textUnderCursor() const;

private:
  QStringListModel completerModel_;
  std::unique_ptr<QCompleter> completer_;
};

} // namespace Ui

#endif // JONES_DEBUGGER_COMMAND_PROMPT_HH
