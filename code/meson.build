dir = include_directories('.')
code = files('app.c')

executable('fintastic',
    sources: ['main.c', code],
    include_directories: dir,
    dependencies: deps,
    install: true)
