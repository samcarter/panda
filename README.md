![](https://raw.githubusercontent.com/samcarter/panda/main/ICON.png)

# panda

[![License](https://img.shields.io/github/license/samcarter/panda.svg?color=blue)](https://www.latex-project.org/lppl.txt)
[![GitHub tag](https://img.shields.io/github/tag/samcarter/panda.svg?label=current%20version&color=blue)](https://github.com/samcarter/panda/releases/latest)
[![CTAN](https://img.shields.io/ctan/v/panda.svg?color=blue)](https://ctan.org/pkg/panda)

A package to estimage the blackness of fonts

This project is licensed under the LaTeX Project Public License v1.3c or later, see https://www.latex-project.org/lppl.txt . 

The project repository, including a bug tracker, can be found at https://github.com/samcarter/panda .

### Usage busyPanda

```latex
\documentclass[varwidth]{standalone}

\usepackage{busyPanda}

\newcommand{\bamboo}{%
  \rule{\busyPanda{0.1}\fontcharht\font`I}{\fontcharht\font`I}
}

\begin{document}

normal cmr: \bamboo

\bfseries
bold cmr: \bamboo

\normalfont
\fontfamily{cmbr}

normal cmbr: \bamboo

\bfseries
bold cmbr: \bamboo

\end{document}
```

For more details, please consult the [package documentation](https://github.com/samcarter/panda/blob/main/DOCUMENTATION.pdf).
