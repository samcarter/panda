![](https://raw.githubusercontent.com/samcarter/panda/main/ICON.png)

# panda

[![License](https://img.shields.io/github/license/samcarter/panda.svg?color=blue)](https://www.latex-project.org/lppl.txt)
[![GitHub tag](https://img.shields.io/github/tag/samcarter/panda.svg?label=current%20version&color=blue)](https://github.com/samcarter/panda/releases/latest)
[![CTAN](https://img.shields.io/ctan/v/panda.svg?color=blue)](https://ctan.org/pkg/panda)

A package to estimate the blackness of fonts

One challenge when drawing icons or symbols can be to make them blend in with the surrounding text. If their line widths look good with one font, they can stand out like a sore thumb with another font. The panda package provides tools to automatically adjust line widths etc. to fit in with the surrounding font.

This project is licensed under the LaTeX Project Public License v1.3c or later, see https://www.latex-project.org/lppl.txt . 

The project repository, including a bug tracker, can be found at https://github.com/samcarter/panda .

### Usage CleverPanda
```latex
\documentclass[varwidth,border=1pt]{standalone}

\usepackage{CleverPanda}

\newcommand{\bamboo}{%
  \rule{\CleverPanda{}}{\fontcharht\font`I}
}

\begin{document}

normal cmr: \bamboo

\bfseries
bold cmr: \bamboo

\normalfont
\fontfamily{cmbr}\selectfont
normal cmbr: \bamboo

\bfseries
bold cmbr: \bamboo

\end{document}
```

### Usage BusyPanda

```latex
\documentclass[varwidth,border=1pt]{standalone}

\usepackage{BusyPanda}

\newcommand{\bamboo}{%
  \rule{\BusyPanda{0.125}\fontcharht\font`I}{\fontcharht\font`I}
}

\begin{document}

normal cmr: \bamboo

\bfseries
bold cmr: \bamboo

\normalfont
\fontfamily{cmbr}\selectfont
normal cmbr: \bamboo

\bfseries
bold cmbr: \bamboo

\end{document}
```

For more details, please consult the [package documentation](https://github.com/samcarter/panda/blob/main/DOCUMENTATION.pdf).
