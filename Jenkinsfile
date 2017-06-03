//  -*- mode: groovy-mode

pipeline {
    agent any 

    stages {
        stage('Build CC LX') { 
            steps { 
                parallel(
                    'build': {
                        node('linux') {
                            sh './Installation/Pipeline/build_cc_lx.sh 16'
                        }
                    },

                    'jslint': {
                        node('linux || mac') {
                            script {
                                try {
                                    sh './Installation/Pipeline/jslint.sh'
                                }
                                catch (exc) {
                                    currentBuild.result = 'UNSTABLE'
                                }
                            }
                        }
                    }
                )
            }
        }
    }
}
