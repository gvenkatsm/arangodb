//  -*- mode: groovy-mode

pipeline {
    agent any 

    stages {
        stage('GIT CC') {
            steps { 
                node('master') {
                    milestone(1)

                    checkout scm

                    stash includes: '**', name: 'source'
                }
            }
        }

        stage('Build CC LX') { 
            steps { 
                node('linux') {
                    milestone(2)

                    unstash 'source'

                    sh './Installation/Pipeline/build_cc_lx.sh 16'

                    stash includes: 'build/**,etc/**,js/**,scripts/**,tests/**,UnitTests/**', name: 'build-cc-lx'
                }
            }
        }

        stage('Basic Tests') {
            steps {
                parallel(
                    'jsunity': {
                        node('linux or mac') {
                            script {
                                try {
                                    sh './Installation/Pipeline/jslint.sh'
                                }
                                catch (exc) {
                                    currentBuild.result = 'UNSTABLE'
                                }
                            }
                        }
                    },

                    'test-ss-mm-cc-lx': {
                        node('linux') {
                            unstash 'build-cc-lx'

                            sh '/Installation/Pipeline/test_ss_mm_cc_lx.sh'
                        }
                    }
                )
            }
        }
    }
}
