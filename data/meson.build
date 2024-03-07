fs = import('fs')

data_files = [
    'data.txt',
    'result_win.txt',
    'result_lose.txt',
    'determine_rock.txt',
    'determine_scissors.txt',
    'determine_paper.txt'
]

foreach file : data_files
    fs.copyfile(file, join_paths(meson.project_source_root(), file))
endforeach

install_data(data_files, install_dir: get_option('datadir'))
