if get_option('with_test').enabled()
    test_deps = [
        dependency('fscl-xtest-c'),
        dependency('fscl-xmock-c')
    ]

    test_src = ['xunit_runner.c']
    test_cubes = ['cases', 'input', 'player', 'determine', 'scoreboard']

    foreach cube : test_cubes
        test_src += ['xtest_' + cube + '.c']
    endforeach

    pizza = executable('xcli', [test_src, code], include_directories: dir, dependencies : [test_deps, deps])
    test('Execute project Xunit tests', pizza)

endif
