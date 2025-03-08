PS=$(ps | grep miniRT | sed "s/^[ ]*\([0-9]*\).*/\1/g" | tr '\n' ' ')
kill ${PS}