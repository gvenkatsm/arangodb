//  -*- mode: groovy-mode

pipeline {
    agent any 

    stages {
        stage('Checkout') {
            steps { 
                node('master') {
                    milestone(1)

                    script {
                        retry(3) {
                            try {
                                checkout scm
                            }
                            catch (err) {
                                echo "GITHUB checkout failed, retrying in 5min"
                                sleep 300
                            }
                        }
                    }

                    sh 'rm -rf build build-jenkins'

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

                    stash includes: 'build/**,etc/**,Installation/Pipeline/**,js/**,scripts/**,tests/**,UnitTests/**', name: 'build-cc-lx'
                }
            }
        }

        stage('Basic Tests') {
            steps {
                parallel(
                    'jsunity': {
                        node('linux || mac') {
                            unstash 'build-cc-lx'

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

                            sh './Installation/Pipeline/test_ss_mm_cc_lx.sh 8'
                        }
                    }
                )
            }
        }
    }
}
