dir = include_directories('.')
code = files(
    'app.c',
    'player.c',
    'determine',
    'scoreboard.c')

executable('fintastic',
    sources: ['main.c', code],
    include_directories: dir,
    dependencies: deps,
    install: true)
