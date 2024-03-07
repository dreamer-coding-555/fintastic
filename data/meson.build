data_files = [
    'data.txt',
    'result_win.txt',
    'result_lose.txt',
    'determine_rock.txt',
    'determine_scissors.txt',
    'determine_paper.txt'
]

foreach file : data_files
    configure_file(input: file, output: join_paths(meson.source_root(), file), copy: true)
endforeach

install_data(data_files, install_dir: get_option('datadir'))